#pragma once
#include "Queue.h"
class List :
	public Queue
{
private:
	Queue::Element* get_element(size_t);

public:
	List();
	List(int* arr, size_t amount);
	~List();

	void menu()	override;

	void push_back(int);	// вставляет элемент сзади
	int  pop_back();		// возвращает последний элемент после удаления
	void push_front(int);	// вставляет элемент спереди
	int  pop_front();		// возвращает первый элемент после удаления

	void push(size_t, int);	// вставляет n-ый элемент
	int  pop(size_t);		// возвращает n-ый элемент после удаления

	bool is_empty()	override;	// возвращает true, если стек пуст
	int& top()		override;	// возвращает первый элемент без удаления
	int& back();				// возвращает последний элемент без удаления
	int& operator[](size_t const& index);
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};
