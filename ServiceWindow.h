//
//ServiceWindow.hpp
//
//QueueSystem
//

#ifndef ServiceWindow_hpp
#define ServiceWindow_hpp

#include "Node.hpp"

enum WindowStatus{
	SERVICE,
	IDLE.
};

class ServiceWindow{
public:
	inline ServiceWindow(){
		window_status = IDLE;
	};

	inline bool isIdle() const {
		if(window_status == IDLE){
			return ture;
		}else{

		return false;
		}
	}

	inline void serveCustomer(Customer &customer) {
		window_status = customer;
	}
	inline void setBusy(){
		window_status = SERVICE;

	}

	inline int getCustomerArriveTime()const{
		return customer.arrive_time;
	}

	inline int getCustomerDuration()const{

		return customer.duration;
	}
private:
	Customer customer;
	WindowStatus window_status;

};
