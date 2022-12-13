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
			std::cout << "\n\tМеню Стека"
				<< "\n\t1.Добавить элемент"
				<< "\n\t2.Извлечь элемент"
				<< "\n\t3.Посмотреть верхний элемент"
				<< "\n\t4.Вывести на экран"
				<< "\n\t0.Назад\n->";
			std::cin >> m;

			switch (m)
			{
			case 1: {
				int num;
				std::cout << "\t\tВведите число: ";
				std::cin >> num;
				this->push(num);
				std::cout << "\t\tДанные успешно добавлены\n";
				break; }
			case 2: {
				std::cout << "\t\tВерхний элемент извлечен: " << this->pop() << "\n";
				break; }
			case 3: {
				std::cout << "\t\tВерхний элемент: " << this->top() << "\n";
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
			std::cout << "\t\tСтек пустой!\n";
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
	if (is_empty()) throw - 1;		// если элементов нет, вызываем исключения
	int temp_data = last->data;
	if (last == first)		// если элемент 1
	{
		delete last;
		first = last = nullptr;
	}
	else						// если элементов больше 1
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
	std::string str = " Размер: " + std::to_string(_size) + "\n";
	Queue::Element* temp = last;
	while (temp->prev != nullptr)
	{
		str += " | " + std::to_string(temp->data) + " |\n";
		temp = temp->prev;
	}
	str += " | " + std::to_string(temp->data) + " |\n  \\__/\n";
	return str;
}