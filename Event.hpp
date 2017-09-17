//
//  Event.hpp
//  QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include "Random.hpp"

struct Event {
    int occur_time;
    
    // 使用 -1 表示到达事件, >=0 表示离开事件, 同时数值表示所离开的服务窗口
    int event_type;
    
    Event* next;
    
    // 默认为到达事件，发生事件随机
    Event(int occur_time = Random::getRandom(POISSON, 0.5),
          int event_type = -1):
        occur_time(occur_time),
        event_type(event_type),
        next(NULL) {}
};

#endif /* Event_hpp */
