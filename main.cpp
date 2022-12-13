#include <iostream>
#include <string>
#include <Windows.h>
#include "Keeper.h"
#include "Queue.h"
#include "List.h"
#include "Deck.h"
#include "Stack.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper keeper;
	int c;

	while (true)
	{
		cout << "\n����"
			<< "\n1.�������������� �� �����"
			<< "\n2.�������� ���������"
			<< "\n3.����� ������ �� �����"
			<< "\n4.������� ���������"
			<< "\n5.���������� � ����"
			<< "\n6.��������������"
			<< "\n7.�������� ���� ������"
			<< "\n0.����� ��� ����������\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (keeper.load("save.txt"))
				cout << "\t������ ������� ���������\n";
			else
				cout << "\t���� �� ������ ��� ��������\n";
			break; }
		case 2: {
			int type;
			cout << "\t�������� ���������:\n"
				<< "\n\t1.������"
				<< "\n\t2.���"
				<< "\n\t3.����\n\t->";
			cin >> type;
			switch (type)
			{
			case 1: {
				keeper.add(new List());
				break; }
			case 2: {
				keeper.add(new Deck());
				break; }
			case 3: {
				keeper.add(new Stack());
				break; }
			default: cout << "\t������� ������������ ��������!\n";
			}
			cout << "\t��������� �" << keeper.size() << " ������� ��������\n";
			break; }
		case 3: {
			if (keeper.size() == 0)
				cout << "\t���������� �����������.\n";
			else
				keeper.print();
			break; }
		case 4: {
			if (keeper.size() == 0)
				cout << "\t���������� �����������.\n";
			else
			{
				size_t num;
				cout << "\t�������� ���������. ��������: �"
					<< (keeper.size() == 1 ? "" : "1 - �")
					<< (keeper.size() == 1 ? 1 : keeper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					keeper.del(num - 1);
					cout << "\t������ ������� �������\n";
				}
				catch (int)
				{
					cout << "\t������� ������������ ��������!\n";
				}
			}
			break; }
		case 5: {
			
			keeper.save("save.txt");
				//cout << "\t������ ������� ���������\n";
			//else
				//cout << "\t��� ���������� ��������� ������\n";
			break; }
		case 6: {
			if (keeper.size() == 0)
				cout << "\t���������� �����������.\n";
			else
			{
				size_t num;
				cout << "\t�������� ���������. ��������: �"
					<< (keeper.size() == 1 ? "" : "1 - �")
					<< (keeper.size() == 1 ? 1 : keeper.size())
					<< "\n\t->";
				cin >> num;
				if (num > 0 && num < keeper.size() + 1)
					keeper[num - 1]->menu();
				else
					cout << "\t������� ������������ ��������!\n";
			}
			break; }
		case 7: {
			keeper.del_all();
			break;
		}
		case 0: {
			cout << "\t\t  ��� ������������� ������ ����� �������!"
				<< "\n\t\t  ����������?(1-�� / 0-���)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}