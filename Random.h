//
//Random.hpp
//
//QueueSystem

#ifdef Random_hpp
#define Random_hpp

#include <cstdlib>
#include <cmath>


class Random{
public：
	//［0，1）之间的服从均匀分布的随机值
	static double unifom(double max = 1){
		return ((double)std::rand() / (RAND_MAX))*max;

	}
};


#endif //Random_hpp
