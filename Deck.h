#pragma once
#include "Queue.h"
class Deck :
	public Queue
{
public:
	Deck();
	Deck(int* arr, size_t amount);
	~Deck();

	void menu()	override;

	void push_back(int);	// вставляет элемент сзади
	int  pop_back();		// возвращает последний элемент после удаления
	void push_front(int);	// вставляет элемент спереди
	int  pop_front();		// возвращает первый элемент после удаления

	bool is_empty()	override;	// возвращает true, если пуст
	int& top()		override;	// возвращает первый элемент без удаления
	int& back();				// возвращает последний элемент без удаления
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};