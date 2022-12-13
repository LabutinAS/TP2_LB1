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

	void push_back(int);	// ��������� ������� �����
	int  pop_back();		// ���������� ��������� ������� ����� ��������
	void push_front(int);	// ��������� ������� �������
	int  pop_front();		// ���������� ������ ������� ����� ��������

	bool is_empty()	override;	// ���������� true, ���� ����
	int& top()		override;	// ���������� ������ ������� ��� ��������
	int& back();				// ���������� ��������� ������� ��� ��������
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};