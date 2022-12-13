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
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить контейнер"
			<< "\n3.Вывод данных на экран"
			<< "\n4.Удалить контейнер"
			<< "\n5.Сохранение в файл"
			<< "\n6.Редактирование"
			<< "\n7.Удаление всех данных"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (keeper.load("save.txt"))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {
			int type;
			cout << "\tВыбирите контейнер:\n"
				<< "\n\t1.Список"
				<< "\n\t2.Дек"
				<< "\n\t3.Стек\n\t->";
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
			default: cout << "\tВыбрано недопустимое значение!\n";
			}
			cout << "\tКонтейнер №" << keeper.size() << " успешно добавлен\n";
			break; }
		case 3: {
			if (keeper.size() == 0)
				cout << "\tКонтейнеры отсутствуют.\n";
			else
				keeper.print();
			break; }
		case 4: {
			if (keeper.size() == 0)
				cout << "\tКонтейнеры отсутствуют.\n";
			else
			{
				size_t num;
				cout << "\tВыбирите Контейнер. Доступны: №"
					<< (keeper.size() == 1 ? "" : "1 - №")
					<< (keeper.size() == 1 ? 1 : keeper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					keeper.del(num - 1);
					cout << "\tДанные успешно удалены\n";
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 5: {
			
			keeper.save("save.txt");
				//cout << "\tДанные успешно сохранены\n";
			//else
				//cout << "\tПри сохранении произошла ошибка\n";
			break; }
		case 6: {
			if (keeper.size() == 0)
				cout << "\tКонтейнеры отсутствуют.\n";
			else
			{
				size_t num;
				cout << "\tВыбирите контейнер. Доступны: №"
					<< (keeper.size() == 1 ? "" : "1 - №")
					<< (keeper.size() == 1 ? 1 : keeper.size())
					<< "\n\t->";
				cin >> num;
				if (num > 0 && num < keeper.size() + 1)
					keeper[num - 1]->menu();
				else
					cout << "\tВыбрано недопустимое значение!\n";
			}
			break; }
		case 7: {
			keeper.del_all();
			break;
		}
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}