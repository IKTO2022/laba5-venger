#include "include/notebook.h"

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// Для разных типов систем подгружаются разные библиотеки с sleep
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;


void showAll(vector<Notebook> &ns) {
	cout << "\n << Список устройств >>" << endl;
	for (int i = 0; i < ns.size(); i++) {
		cout << "#" << i+1 << " Состояние: " << ns[i].getState() << endl; 
	}
}


// Интерактивное меню, которое меняется вместе с параметрами
void changeState(vector<Notebook> &ns) {
	int id;
	int max = ns.size();
	cout << "Введите id устройства (число от 1 до " << max << "): ";
	if (!(cin >> id) || (id > max)) {
		cout << "Такого устройства нет!!!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	
	string state;
	int choice;	
	do {
		state = ns[id-1].getState();
		sleep(1);
		cout << "\n<< Меню действий >>" << endl;

		if (state == "Disabled") {
			cout << "1. Включить " << endl;
			cout << "2. Пинг " << endl;
			cout << "3. Подробнее об устройстве" << endl;
			cout << "4. Назад" << endl;
		}
		else {
			cout << "1. Выключить " << endl;
			cout << "2. Пинг " << endl;
			cout << "3. Подробнее об устройстве" << endl;

			if (!(state == "Sleep")) {
				cout << "4. Погрузить в сон " << endl;
			} else {
				cout << "4. Пробудить ото сна " << endl;
			}
			
			if (state != "Sleep") {
				if (ns[id-1].getInternetState()) {
					cout << "5. Выключить интернет" << endl;
				} else {
					cout << "5. Включить интернет" << endl;
				}
				cout << "6. Назад" << endl;
			} else {
				cout << "5. Назад" << endl;
			}
		}
		cout << "\nВыберите действие: ";

	
		if (!(cin >> choice)) {
			cout << "\nНекорректный ввод! Попробуйте ещё раз!" << endl;
			
			// Фикс сломанного cin
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	
			continue;	
		}

		switch(choice) {
			case 1:
				ns[id-1].powerSwitch();
				break;

			case 2:
				ns[id-1].ping();
				break;

			case 3:
				ns[id-1].showInfo();
				break;

			case 5:
				if (state != "Disabled") { 
					if (state != "Sleep") {
						ns[id-1].internetSwitch();
					}	else {
						choice = 6;
					}
				} else {
					cout << "Некорректный ввод!" << endl;
				}
				break;

			case 4:
				if (state != "Disabled") {
					ns[id-1].sleepSwitch();
				}	else {
					choice = 6;
				}
				break;
	
			case 6:
				if (state == "Disabled") {
					choice = 0;
				}
				break;

			default:
				cout << "Некорректный ввод!" << endl;
				break;
		}	
	} 
	while (choice != 6);
}


int main() {
	// Объявление массива с объектами
	vector<Notebook> notebooks;
	notebooks.push_back(Notebook(1));

	int choice;
	do {	
		sleep(1);
		cout << "\n<< Меню действий >>" << endl;
		cout << "1. Добавить устройство" << endl;
		cout << "2. Показать все устройства" << endl;
		cout << "3. Взаимодействовать с устройством" << endl;
		cout << "4. Выйти" << endl;

		cout << "\nВыберите действие: ";
		if (!(cin >> choice)) {
			cout << "Некорректный ввод! Попробуйте ещё раз!" << endl;
			// Фикс сломанного cin
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		
		switch (choice) {
			case 1:
				{
					int num = notebooks.size() + 1;
					string oc;
					cout << "\nВведите название OC (по умолч. Windows): ";
					cin.ignore();
					getline(cin, oc);
					if (oc.size()) {	
						notebooks.push_back(Notebook(num, oc));
					} else {
						notebooks.push_back(Notebook(num));
					}
					break;
				}

			case 2:
				showAll(notebooks);
				break;

			case 3: 
				changeState(notebooks);
				break;

			case 4:
				break;
			
			default:
				cout << "Некорректный ввод!" << endl;
		}
	}
	while (choice != 4);

	// Очищаем память перед выходом
	notebooks.clear();
	return 1;
}
