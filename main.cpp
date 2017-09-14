//
//main.cpp

//QueueSytem
//


#include "QueueSystem.h"

#include <iostream>
#include <cstdlib>

int main(){
	std::srand((unsigned)std::time(0));//使用当前时间作为随机数种子
	int total_service_time = 240;//按分钟计算

	int window_num = 4;
	int simulate_num = 100000;//模拟次数

	QueueSytem system(total_service_time,window_num);

	system.simulate(simulate_num);

	std::cout << "the average time of customer stay in bank:" << system.getAvgStayTime() << std::endl;

	std::cout << "The number of customer arrive bank per minute:" << system.getAvgCustomers() << std::endl;

	return 0;

}

