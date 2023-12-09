#include "include/notebook.h"

using namespace std;

Notebook::Notebook(int id) : Device(id) {
	this->id=id;
	this->state="Working";
	setOperationSystem("Windows");
}


Notebook::Notebook(int id, string oc) : Device(id) {
	this->state="Working";
	setOperationSystem(oc);
}	


string Notebook::getState() {
	return this->state;
}


void Notebook::sleepSwitch() {
	if (this->state == "Sleep") {
		this->state = "Working";
		cout << "Устройство выведено из состояния сна..." << endl;
	} else {
		this->state="Sleep";
		cout << "Устройство погружено в сон..." << endl;
	}
}


void Notebook::powerSwitch() {
	if (this->power == true) {
		this->power=false;
		this->state="Disabled";
	}
	else {
		this->power=true;
		this->state="Working";
	}
}


void Notebook::setOperationSystem(string name) {
	this->oc = name;	
}


// Переопределение виртуальной функции базового класса
void Notebook::showInfo() {
	cout << "\nИмя устройства: Notebook #" << this->id << endl;
	cout << "Операционная система: " << this->oc << endl;
	cout << "Состояние: " << this->state << endl;
	cout << "Интернет: " << this->internet << endl;
	if (this->internet) {
		cout << "IP адрес: " << this->ip << endl;
	}
}


void Notebook::ping() {
	if ((this->internet == true) && (this->power == true) && (this->state != "Sleep")) {
		for (int i = 0; i < 3; i++) {
			cout << "Reply from " << this->ip << " bytes=32 time=0ms TTL=124" << endl;
			sleep(1);	
		}
	} else {
		cout << "Устройство " << this->ip << " вне досигаемости!" << endl; 
	}
}
