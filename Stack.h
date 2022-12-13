#pragma once
#include "Queue.h"
class Stack :
	public Queue
{
public:
	Stack();
	Stack(int* arr, size_t amount);
	~Stack();

	void menu()	override;

	void push(int);	// вставляет элемент сверху
	int  pop();		// возвращает верхний элемент после удаления из стека

	bool is_empty()	override;	// возвращает true, если пуст
	int& top()		override;	// возвращает верхний элемент без удаления
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};
