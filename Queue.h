#pragma once
#include <iostream>
#include <string>
class Queue
{
protected:
	size_t _size = 0;
	class Element
	{
	public:
		int data = 0;
		Element* prev = nullptr;
		Element* next = nullptr;
	};
	Element* last = nullptr;
	Element* first = nullptr;

public:
	Queue();
	virtual ~Queue();
	virtual void menu() = 0;
	virtual bool is_empty() = 0;	// возвращает true, если пуст
	virtual int& top() = 0;		// возвращает верхний элемент без удаления
	virtual std::string get_string_data() = 0;
	virtual std::string get_print_data() = 0;
};
