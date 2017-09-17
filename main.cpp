//
// main.cpp
// QueueSystem
//
//  Created by Changkun on 16/7/6.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//

#include "QueueSystem.hpp"

#include <iostream>
#include <cstdlib>

int main() {
    
#ifdef __APPLE__
    std::srand((unsigned)std::time(0)); //  使用当前时间作为随机数种子
#else
    std::srand(time(0));
#endif

    int total_service_time = 240;
    int window_num         = 4;
    int simulate_num       = 100000;
    
    QueueSystem system(total_service_time, window_num);
    system.simulate(simulate_num);
    
    std::cout << "The average time of customer stay in bank: "
    << system.getAvgStayTime() << std::endl;
    std::cout << "The number of customer arrive bank per minute: " << system.getAvgCustomers() << std::endl;
    
    return 0;
}
