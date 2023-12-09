#include "include/device.h"

using namespace std;

Device::Device(int id) {
	cout << "\nДобавлено устройство #" << id << endl; 
	this->id = id;
	this->power = true;
	this->internet = true;
	setIp();
}


void Device::setIp() {
	if (this->internet == true) {
		this->ip = "192.168.1."+ to_string(this->id);
		cout << "Устройству присвоен адрес - " << this->ip << endl;
	} else {
		cout << "Интернет на устройстве " << this->id << " выключен!" << endl;
	}
}
	

void Device::internetSwitch() {
	this->internet = !this->internet;
}

	
bool Device::getInternetState() {
	return this->internet;
}


void Device::showInfo() {
	cout << "\nИмя устройства: Device #" << this->id << endl;
	cout << "Питание: " << this->power << endl;
	cout << "Интернет: " << this->internet << endl;
	if (this->internet) {
		cout << "IP адрес: " << this->ip << endl;
	}		
}
