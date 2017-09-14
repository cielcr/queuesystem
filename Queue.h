//
//Queue.hpp
//
//QueueSystem
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <cstdlib>

#include "Event.hpp"

//代头节点的队列

templte <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	void clearQueue();//清空队列

	T＊ enqueue(T &node);
	T* dequeue();
	T* orderEnqueue(Event &event);//只适用于事件入队

	int length();

private:
	T *front;//头节点
	T ＊rear;//队尾



};
#endif //Queue_hpp
