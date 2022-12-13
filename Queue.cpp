#include "Queue.h"

Queue::Queue() : _size(_size), last(last), first(first)
{
	std::cout << "Queue\n";
}

Queue::~Queue()
{
	std::cout << "~Queue\n";
}