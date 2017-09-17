//
//  QueueSystem.cpp
//  QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#include "QueueSystem.hpp"
#include "Random.hpp"
#include "Event.hpp"

QueueSystem::QueueSystem(int total_service_time, int window_num):
    total_service_time(total_service_time),
    window_num(window_num),
    total_customer_stay_time(0),
    total_customer_num(0) {
    // 创建服务窗口
    this->windows = new ServiceWindow[window_num];
}
QueueSystem::~QueueSystem() {
    delete[] windows;
}
void QueueSystem::simulate(int simulate_num) {
    double sum = 0;
    for (int i = 0; i != simulate_num; ++i) {
        sum += run();
    }
    avg_stay_time = (double)sum / simulate_num;
    avg_customers = (double)total_customer_num / (total_service_time*simulate_num);
}

double QueueSystem::run() {
    this->init();
    while (current_event) {
        // 判断当前事件类型
        if (current_event->event_type == -1) {
            customerArrived();
        } else {
            customerDeparture();
        }
        delete current_event;
        // 获得新的事件
        current_event = event_list.dequeue();
    };
    this->end();
    // 返回顾客的平均逗留时间
    return (double)total_customer_stay_time/total_customer_num;
}

// 系统开启运行, 初始化事件链表, 部署第一个事件
void QueueSystem::init() {
    // 第一个事件肯定是到达事件, 使用默认构造
    Event *event = new Event;
    current_event = event;
}

void QueueSystem::end() {
    // 设置所有窗口空闲
    for (int i=0; i != window_num; ++i) {
        windows[i].setIdle();
    }
    // 顾客队列清空
    customer_list.clearQueue();
    
    // 事件列表清空
    event_list.clearQueue();

}

int QueueSystem::getIdleServiceWindow() {
    for (int i=0; i!=window_num; ++i) {
        if (windows[i].isIdle()) {
            return i;
        }
    }
    return -1;
}

// 处理用户到达事件
void QueueSystem::customerArrived() {
    
    total_customer_num++;
    int intertime = Random::getRandom(POISSON, 0.5);     // 下一个顾客到达的时间间隔
    // 生成下一个顾客的到达事件
    // 下一个顾客的到达时间 = 当前时间的发生时间 + 下一个顾客到达的时间间隔
    int time = current_event->occur_time + intertime;
    Event temp_event(time);
    
    // 如果下一个顾客的到达时间小于服务的总时间，就把这个事件插入到事件列表中
    // 同时将这个顾客加入到 customer_list 进行排队
    if (time < total_service_time) {
        event_list.orderEnqueue(temp_event);
    } // 否则不列入事件表，且不加入 cusomer_list
    
    
    // 处理当前事件中到达的顾客
    Customer *customer = new Customer(current_event->occur_time);
    if (!customer) {
        exit(-1);
    }
    customer_list.enqueue(*customer);
    
    // 如果当前窗口有空闲窗口，那么直接将这个顾客送入服务窗口
    int idleIndex = getIdleServiceWindow();
    if (idleIndex >= 0) {
        customer = customer_list.dequeue();
        windows[idleIndex].serveCustomer(*customer);
        windows[idleIndex].setBusy();
        
        // 顾客到窗口开始服务时，就需要插入这个顾客的一个离开事件到 event_list 中
        // 离开事件的发生时间 = 当前时间事件的发生时间 + 服务时间
        Event temp_event(current_event->occur_time + customer->duration, idleIndex);
        event_list.orderEnqueue(temp_event);
    }
    delete customer;
}

// 处理用户离开事件
void QueueSystem::customerDeparture() {
    // 如果离开事件的发生时间比中服务时间大，我们就不需要做任何处理
    if (current_event->occur_time < total_service_time) {
        // 顾客逗留时间 = 当前顾客离开时间 - 顾客的到达时间
        total_customer_stay_time += current_event->occur_time - windows[current_event->event_type].getCustomerArriveTime();
        // 如果队列中有人等待，则立即服务等待的顾客
        if (customer_list.length()) {
            Customer *customer;
            customer = customer_list.dequeue();
            windows[current_event->event_type].serveCustomer(*customer);
            
            // 离开事件
            Event temp_event(
                current_event->occur_time + customer->duration,
                current_event->event_type
            );
            event_list.orderEnqueue(temp_event);
            
            delete customer;
        } else {
            // 如果队列没有人，且当前窗口的顾客离开了，则这个窗口是空闲的
            windows[current_event->event_type].setIdle();
        }
        
    }
}
