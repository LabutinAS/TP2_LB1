#include "List.h"

List::List()
{
	std::cout << "List\n";
}

List::List(int* arr, size_t amount)
{
	std::cout << "List\n";
	for (size_t i = 0; i < amount; i++)
		this->push_back(arr[i]);
}

List::~List()
{
	std::cout << "~List\n";
	while (!this->is_empty())
		this->pop_back();
}

void List::menu()
{
	int m;
	while (true)
	{
		try
		{
			std::cout << "\n\t���� ������"
				<< "\n\t1.�������� ������� � ������"
				<< "\n\t2.������� ������� �������"
				<< "\n\t3.�������� ������� � �����"
				<< "\n\t4.������� ������� �����"
				<< "\n\t5.�������� n-�� �������"
				<< "\n\t6.������� n-�� �������"
				<< "\n\t7.���������� ������ �������"
				<< "\n\t8.���������� ��������� �������"
				<< "\n\t9.���������� n-�� �������"
				<< "\n\t10.������� �� �����"
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
				int num, index;
				std::cout << "\t\t������� ����� ��������: ";
				std::cin >> index;
				std::cout << "\t\t������� �����: ";
				std::cin >> num;
				this->push(index, num);
				std::cout << "\t\t������ ������� ���������\n";
				break; }
			case 6: {
				int index;
				std::cout << "\t\t������� ����� ��������: ";
				std::cin >> index;
				std::cout << "\t\t������� �" << index << " ��������: " << this->pop(index) << "\n";
				break; }
			case 7: {
				std::cout << "\t\t������ �������: " << this->top() << "\n";
				break; }
			case 8: {
				std::cout << "\t\t��������� �������: " << this->back() << "\n";
				break; }
			case 9: {
				int index;
				std::cout << "\t\t������� ����� ��������: ";
				std::cin >> index;
				std::cout << "\t\t������� �" << index << ": " << this->operator[](index) << "\n";
				break; }
			case 10: {
				std::cout << this->get_print_data();
				break; }
			case 0: {
				return; }
			}
		}
		catch (int)
		{
			std::cout << "\t\t������ ������!\n";
		}
		catch (std::string err)
		{
			std::cout << "\t\t������� " << err;
		}
	}
}

void List::push_back(int new_data)
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

int List::pop_back()
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

void List::push_front(int new_data)
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

int List::pop_front()
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

void List::push(size_t index, int new_data)
{
	if (index < 0) throw - 1;
	if (is_empty()) // ���� ��������� ���
	{
		first = last = new Queue::Element;
		last->data = new_data;
		last->next = nullptr;
		last->prev = nullptr;
		++_size;
	}
	else if (index == 0)
	{
		this->push_front(new_data);
	}
	else if (index >= _size)
	{
		this->push_back(new_data);
	}
	else
	{
		Queue::Element* temp = get_element(index);
		Queue::Element* temp_new = new Queue::Element;
		temp_new->data = new_data;
		temp_new->prev = temp->prev;
		temp_new->next = temp;
		temp->prev->next = temp_new;
		temp->prev = temp_new;
		++_size;
	}
}

int List::pop(size_t index)
{
	if (is_empty()) throw - 1;
	if (index >= _size || index < 0) throw std::string("�������� ��������");
	int temp_data = 0;
	if (last == first)		// ���� ������� 1
	{
		temp_data = first->data;
		delete first;
		first = last = nullptr;
	}
	else if (index == 0)
	{
		Queue::Element* temp = first->next;
		temp_data = first->data;
		delete first;
		temp->prev = nullptr;
		first = temp;
	}
	else if (index == _size - 1)
	{
		Queue::Element* temp = last->prev;
		temp_data = last->data;
		delete last;
		temp->next = nullptr;
		last = temp;
	}
	else
	{
		Queue::Element* temp = get_element(index);
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		temp_data = temp->data;
		delete temp;
	}
	--_size;
	return temp_data;
}

Queue::Element* List::get_element(size_t index)
{
	if (is_empty()) throw - 1;
	if (index >= _size || index < 0) throw std::string("�������� ��������");
	Queue::Element* temp = index < _size / 2 ? first : last; // ���� ������ ����� � ������� ��������, �� ������� �������� � ����, ����� � ����������
	if (index < _size / 2) // ���� ������ ����� � �������
		for (size_t _i = 0; _i < index; ++_i) // ������� � ������� �� i����
			temp = temp->next; // ������� � ����������
	else // ���� ������ ����� � ����������
		for (size_t _i = _size - 1; _i > index; --_i) // ������� � ���������� �� i����
			temp = temp->prev; // ������� � �����������
	return temp;
}

bool List::is_empty()
{
	return !_size;
}

int& List::top()
{
	if (is_empty()) throw - 1;
	return first->data;
}

int& List::back()
{
	if (is_empty()) throw - 1;
	return last->data;
}

int& List::operator[](size_t const& index)
{
	return get_element(index)->data;
}

std::string List::get_string_data()
{
	std::string str = "List\n" + std::to_string(_size);
	Queue::Element* temp = first;
	while (temp != nullptr)
	{
		str += " " + std::to_string(temp->data);
		temp = temp->next;
	}
	str += "\n";
	return str;
}

std::string List::get_print_data()
{
	if (is_empty()) throw - 1;
	std::string str = " ������: " + std::to_string(_size) + "\n";
	Queue::Element* temp = first;
	while (temp != nullptr)
	{
		str += " [ " + std::to_string(temp->data) + " ]  ";
		temp = temp->next;
	}
	str += "\n";
	return str;
}