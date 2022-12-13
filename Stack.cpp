#include "Stack.h"

Stack::Stack()
{
	std::cout << "Stack\n";
}

Stack::Stack(int* arr, size_t amount)
{
	std::cout << "Stack\n";
	for (size_t i = 0; i < amount; i++)
		this->push(arr[i]);
}

Stack::~Stack()
{
	std::cout << "~Stack\n";
	while (!this->is_empty())
		this->pop();
}

void Stack::menu()
{
	int m;
	while (true)
	{
		try
		{
			std::cout << "\n\t���� �����"
				<< "\n\t1.�������� �������"
				<< "\n\t2.������� �������"
				<< "\n\t3.���������� ������� �������"
				<< "\n\t4.������� �� �����"
				<< "\n\t0.�����\n->";
			std::cin >> m;

			switch (m)
			{
			case 1: {
				int num;
				std::cout << "\t\t������� �����: ";
				std::cin >> num;
				this->push(num);
				std::cout << "\t\t������ ������� ���������\n";
				break; }
			case 2: {
				std::cout << "\t\t������� ������� ��������: " << this->pop() << "\n";
				break; }
			case 3: {
				std::cout << "\t\t������� �������: " << this->top() << "\n";
				break; }
			case 4: {
				std::cout << this->get_print_data();
				break; }
			case 0: {
				return; }
			}
		}
		catch (int)
		{
			std::cout << "\t\t���� ������!\n";
		}
	}
}

void Stack::push(int new_data)
{
	if (is_empty())
	{
		first = last = new Queue::Element;
		last->prev = nullptr;
		last->next = nullptr;
		last->data = new_data;
	}
	else
	{
		Queue::Element* temp = new Queue::Element;
		temp->data = new_data;
		temp->prev = last;
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
	_size++;
}

int Stack::pop()
{
	if (is_empty()) throw - 1;		// ���� ��������� ���, �������� ����������
	int temp_data = last->data;
	if (last == first)		// ���� ������� 1
	{
		delete last;
		first = last = nullptr;
	}
	else						// ���� ��������� ������ 1
	{
		Queue::Element* temp = last->prev;
		delete last;
		temp->next = nullptr;
		last = temp;
	}
	--_size;
	return temp_data;
}

bool Stack::is_empty()
{
	return !_size;
}

int& Stack::top()
{
	if (is_empty()) throw - 1;
	return last->data;
}

std::string Stack::get_string_data()
{
	std::string str = "Stack\n" + std::to_string(_size);
	Queue::Element* temp = first;
	while (temp != nullptr)
	{
		str += " " + std::to_string(temp->data);
		temp = temp->next;
	}
	str += "\n";
	return str;
}

std::string Stack::get_print_data()
{
	if (is_empty()) throw - 1;
	std::string str = " ������: " + std::to_string(_size) + "\n";
	Queue::Element* temp = last;
	while (temp->prev != nullptr)
	{
		str += " | " + std::to_string(temp->data) + " |\n";
		temp = temp->prev;
	}
	str += " | " + std::to_string(temp->data) + " |\n  \\__/\n";
	return str;
}