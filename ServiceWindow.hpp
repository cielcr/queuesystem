//
//  ServiceWindow.hpp
//  QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#ifndef ServiceWindow_hpp
#define ServiceWindow_hpp

#include "Node.hpp"

enum WindowStatus {
    SERVICE,
    IDLE,
};

class ServiceWindow {
public:
    inline ServiceWindow() {
        window_status = IDLE;
    };
    inline bool isIdle() const {
        if (window_status == IDLE) {
            return true;
        } else {
            return false;
        }
    }
    inline void serveCustomer(Customer &customer) {
        this->customer = customer;
    }
    inline void setBusy() {
        window_status = SERVICE;
    }
    inline void setIdle() {
        window_status = IDLE;
    }
    inline int getCustomerArriveTime() const {
        return customer.arrive_time;
    }
    inline int getCustomerDuration() const {
        return customer.duration;
    }
private:
    Customer customer;
    WindowStatus window_status;
};

#endif /* ServiceWindow_hpp */
