#include "Deck.h"

Deck::Deck()
{
	std::cout << "Deck\n";
}

Deck::Deck(int* arr, size_t amount)
{
	std::cout << "Deck\n";
	for (size_t i = 0; i < amount; i++)
		this->push_back(arr[i]);
}

Deck::~Deck()
{
	std::cout << "~Deck\n";
	while (!this->is_empty())
		this->pop_back();
}

void Deck::menu()
{
	int m;
	while (true)
	{
		try
		{
			std::cout << "\n\t���� ����"
				<< "\n\t1.�������� ������� � ������"
				<< "\n\t2.������� ������� �������"
				<< "\n\t3.�������� ������� � �����"
				<< "\n\t4.������� ������� �����"
				<< "\n\t5.���������� ������ �������"
				<< "\n\t6.���������� ��������� �������"
				<< "\n\t7.������� �� �����"
				<< "\n\t0.�����\n->";
			std::cin >> m;

			switch (m)
			{
			case 1: {
				int num;
				std::cout << "\t\t������� �����: ";
				std::cin >> num;
				this->push_front(num);
				std::cout << "\t\t������ ������� ���������\n";
				break; }
			case 2: {
				std::cout << "\t\t������ ������� ��������: " << this->pop_front() << "\n";
				break; }
			case 3: {
				int num;
				std::cout << "\t\t������� �����: ";
				std::cin >> num;
				this->push_back(num);
				std::cout << "\t\t������ ������� ���������\n";
				break; }
			case 4: {
				std::cout << "\t\t��������� ������� ��������: " << this->pop_back() << "\n";
				break; }
			case 5: {
				std::cout << "\t\t������ �������: " << this->top() << "\n";
				break; }
			case 6: {
				std::cout << "\t\t��������� �������: " << this->back() << "\n";
				break; }
			case 7: {
				std::cout << this->get_print_data();
				break; }
			case 0: {
				return; }
			}
		}
		catch (int)
		{
			std::cout << "\t\t��� ������!\n";
		}
	}
}

void Deck::push_back(int new_data)
{
	if (is_empty()) // ���� ��������� ���
	{
		first = last = new Queue::Element;
		last->data = new_data;
		last->next = nullptr;
		last->prev = nullptr;
	}
	else // ���� ���� ������ 1 �������
	{
		Queue::Element* temp = new Queue::Element;
		temp->data = new_data;
		temp->prev = last;
		temp->next = nullptr;
		last->next = temp;
		last = temp;
	}
	++_size;
}

int Deck::pop_back()
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

void Deck::push_front(int new_data)
{
	if (is_empty()) // ���� ��������� ���
	{
		first = last = new Queue::Element;
		last->data = new_data;
		last->next = nullptr;
		last->prev = nullptr;
	}
	else // ���� ���� ������ 1 �������
	{
		Queue::Element* temp = new Queue::Element;
		temp->data = new_data;
		temp->next = first;
		temp->prev = nullptr;
		first->prev = temp;
		first = temp;
	}
	++_size;
}

int Deck::pop_front()
{
	if (is_empty()) throw - 1;		// ���� ��������� ���, �������� ����������
	int temp_data = first->data;
	if (last == first)		// ���� ������� 1
	{
		delete first;
		first = last = nullptr;
	}
	else						// ���� ��������� ������ 1
	{
		Queue::Element* temp = first->next;
		delete first;
		temp->prev = nullptr;
		first = temp;
	}
	--_size;
	return temp_data;
}

bool Deck::is_empty()
{
	return !_size;
}

int& Deck::top()
{
	if (is_empty()) throw - 1;
	return first->data;
}

int& Deck::back()
{
	if (is_empty()) throw - 1;
	return last->data;
}

std::string Deck::get_string_data()
{
	std::string str = "Deck\n" + std::to_string(_size);
	Element* temp = first;
	while (temp != nullptr)
	{
		str += " " + std::to_string(temp->data);
		temp = temp->next;
	}
	str += "\n";
	return str;
}

std::string Deck::get_print_data()
{
	if (is_empty()) throw - 1;
	std::string str = " ������: " + std::to_string(_size) + "\n";
	Element* temp = first;
	while (temp != nullptr)
	{
		str += " [ " + std::to_string(temp->data) + " ]  ";
		temp = temp->next;
	}
	str += "\n";
	return str;
}