#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "List.h"
#include "Deck.h"
#include "Stack.h"
class Keeper
{
private:
	Queue** queues = nullptr;
	size_t _size = 0;

public:
	Keeper();
	~Keeper();
	void add(Queue* elem);
	void del(size_t position);
	void del_all();
	bool save(std::string file);
	bool load(std::string file);
	void print();
	void elems_menu(size_t position);
	size_t size();
	Queue*& operator[](size_t const& index);
};