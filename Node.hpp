//
//  Node.h
//  QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "Random.hpp"

struct Node {
    int arrive_time;
    int duration;
    struct Node *next;
    
    // 默认到达事件为0，需要服务的事件是随机的
    Node(int arrive_time = 0,
         int duration = Random::getRandom(EXPONENTAIL, 0.1)):
        arrive_time(arrive_time),
        duration(duration),
        next(NULL) {}
};

typedef struct Node Node;
typedef struct Node Customer;

#endif /* Node_h */
