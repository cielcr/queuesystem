//
//Eevent.hpp
//QueueSystem
//

#ifndef Event_hpp
#define Event_hpp

#include "Random.hpp"

#define RANDON_PARAMETER 100

struct Event{
	int occur_time;//使用－1表示到达事件，>= 0表示离开事件，同时数值表示所离开的服务窗口
	int event_type;
	//模认为到达事件，发生事件随机
	Eent(int occur_time = Random::uniform(RANDOM_PARAMETER),int event_type = -1):occur_time(occur_time),event_type(event_type),next(NULL){}


};

#endif //Event_hpp

