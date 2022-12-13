#include "Keeper.h"

Keeper::Keeper() : queues(nullptr), _size(0)
{
	std::cout << "Keeper\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper\n";
	for (size_t i = 0; i < _size; i++)
		delete queues[i];
	if (queues) delete[] queues;
}

void Keeper::add(Queue* elem)
{
	Queue** newArray = new Queue * [++_size];
	for (int i = 0; i < _size - 1; i++)
		newArray[i] = queues[i];
	newArray[_size - 1] = elem;
	if (queues) delete[] queues;
	queues = newArray;
}

void Keeper::del(size_t position)
{
	if (position < 0 || position >= _size) throw - 1;
	delete this->queues[position];
	for (int i = position; i < _size; i++)
		this->queues[i] = this->queues[i + 1];
	this->_size--;
}

bool Keeper::save(std::string file)
{
	std::ofstream fout(file);
	if (!fout) return false;
	try {
		if (_size == 0)
			throw std::exception("Данных для сохранения недостаточно");
		//if (!fout) return false;
		fout << std::to_string(_size) << std::endl;
		for (size_t i = 0; i < _size; ++i)
			fout << queues[i]->get_string_data();
	
	std::cout << "Данные сохранены в файл" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	fout.close();
	return true;
}

bool Keeper::load(std::string file)
{
	std::ifstream fin(file);
	if (!fin) return false;

	std::string type;
	size_t queue_amount, inner_amount;

	fin >> queue_amount;
	for (size_t i = 0; i < queue_amount; i++)
	{
		if (fin.eof()) return false;
		fin >> type;
		fin >> inner_amount;
		int* arr = new int[inner_amount];
		for (size_t i = 0; i < inner_amount; i++)
			fin >> arr[i];
		if (type == "List")
			add(new List(arr, inner_amount));
		else if (type == "Deck")
			add(new Deck(arr, inner_amount));
		else if (type == "Stack")
			add(new Stack(arr, inner_amount));
		delete[] arr;
	}
	return true;
}

void Keeper::print()
{
	for (size_t i = 0; i < _size; i++)
		std::cout << "Контейнер №" << i + 1 << ":\n" << (queues[i]->is_empty() ? " Контейнер пустой!\n" : queues[i]->get_print_data());
}

void Keeper::elems_menu(size_t position)
{
	if (position >= _size || position < 0)
		throw - 1;
	queues[position]->menu();
}

size_t Keeper::size()
{
	return _size;
}

Queue*& Keeper::operator[](size_t const& index)
{
	return queues[index];
}

void Keeper::del_all()
{
	try {
		if (_size == 0)
			throw std::exception("Контейнеры отсутсвуют");

		for (int z = _size - 1; z >= 0; z--)
		{
			del(z);

		}
		std::cout << "Удалены все данные" << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
}