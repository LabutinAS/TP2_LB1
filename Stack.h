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

	void push(int);	// ��������� ������� ������
	int  pop();		// ���������� ������� ������� ����� �������� �� �����

	bool is_empty()	override;	// ���������� true, ���� ����
	int& top()		override;	// ���������� ������� ������� ��� ��������
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};
