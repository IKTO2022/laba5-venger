#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "device.h"

#include <string>
#include <iostream>
#include <cmath>

// Для разных типов систем подгружаются разные библиотеки с sleep
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Производный класс с наследованием public
// Доступ к свойствам класса только через методы
class Notebook : public Device 
{
private:
	int id;
	string state;
	string oc;

public:
	// Конструкторы с разными параметрами
	Notebook(int);
	Notebook(int, string);
	string getState();
	void sleepSwitch();
	void powerSwitch();
	void setOperationSystem(string);
	void showInfo(); // Переопределяемая функция
	void ping();

protected:
};

#endif // NOTEBOOK_H
