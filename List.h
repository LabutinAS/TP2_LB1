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

	void push_back(int);	// ��������� ������� �����
	int  pop_back();		// ���������� ��������� ������� ����� ��������
	void push_front(int);	// ��������� ������� �������
	int  pop_front();		// ���������� ������ ������� ����� ��������

	void push(size_t, int);	// ��������� n-�� �������
	int  pop(size_t);		// ���������� n-�� ������� ����� ��������

	bool is_empty()	override;	// ���������� true, ���� ���� ����
	int& top()		override;	// ���������� ������ ������� ��� ��������
	int& back();				// ���������� ��������� ������� ��� ��������
	int& operator[](size_t const& index);
	std::string get_string_data()	override;
	std::string get_print_data()	override;
};
