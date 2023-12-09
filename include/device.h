#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

using namespace std;

// Базовый класс 
class Device 
{
protected:
	int id;
	bool power;
	bool internet;
	string ip;

public:
	Device(int);
	void setIp();
	void internetSwitch();
	bool getInternetState();
	virtual void showInfo(); // переопределяемая функция

private:
};

#endif // DEVICE_H
