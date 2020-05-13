/*
 * gpio.cpp
 *
 *  Created on: 13-May-2020
 *      Author: pmvanker
 */
#include "gpio.h"

list<unsigned char> gpio_list = {2,3,4,14,15,17,18,27,22,23,24,10,9,25,11,8,7,0,1,5,6,12,13,19,16,26,20,21};

/**
 * @param path The sysfs path of the file to be modified
 * @param filename The file to be written to in that path
 * @param value The value to be written to the file
 * @return
 */
int write(string path, string filename, string value){
   ofstream fs;
   fs.open((path + filename).c_str());
   if (!fs.is_open()){
	   perror("GPIO: write failed to open file ");
	   return -1;
   }
   fs << value;
   fs.close();
   return 0;
}
/**
 * @param path The sysfs path of the file to be read
 * @param filename Filename The file to be written to in that path
 * @return
 */
string read(string path, string filename){
   ifstream fs;
   fs.open((path + filename).c_str());
   if (!fs.is_open()){
	   perror("GPIO: read failed to open file ");
    }
   string input;
   getline(fs,input);
   fs.close();
   return input;
}

/**
 * Private write method that writes a single int value to a file in the path provided
 * @param path The sysfs path of the file to be modified
 * @param filename The file to be written to in that path
 * @param value The int value to be written to the file
 * @return
 */
int write(string path, string filename, int value){
   stringstream s;
   s << value;
   return write(path,filename,s.str());
}

/**
 * The constructor will set up the states and export the pin.
 * @param number The GPIO number to be exported
 */
GPIO::GPIO(int number) {
	this->number = number;
	ostringstream s;
	s << "gpio" << number;
	this->name = string(s.str());
	this->path = GPIO_PATH + this->name + "/";
	this->exportGPIO();
	// need to give Linux time to set up the sysfs structure
	usleep(250000); // 250ms delay
}

int GPIO::exportGPIO(){
   return write(GPIO_PATH, "export", this->number);
}

int GPIO::unexportGPIO(){
   return write(GPIO_PATH, "unexport", this->number);
}

int GPIO::setDirection(GPIO::DIRECTION dir){
   switch(dir){
   case INPUT: return write(this->path, "direction", "in");
      break;
   case OUTPUT:return write(this->path, "direction", "out");
      break;
   }
   return -1;
}

GPIO::VALUE GPIO::getValue(){
	string input = read(this->path, "value");
	if (input == "0") return LOW;
	else return HIGH;
}

GPIO::DIRECTION GPIO::getDirection(){
	string input = read(this->path, "direction");
	if (input == "in") return INPUT;
	else return OUTPUT;
}

int GPIO::streamOpen(){
	stream.open((path + "value").c_str());
	return 0;
}
int GPIO::streamWrite(GPIO::VALUE value){
	stream << value << std::flush;
	return 0;
}
int GPIO::streamClose(){
	stream.close();
	return 0;
}

GPIO::~GPIO() {
	this->unexportGPIO();
}

int GPIO::setValue(GPIO::VALUE value){
   switch(value){
   case HIGH: return write(this->path, "value", "1");
      break;
   case LOW: return write(this->path, "value", "0");
      break;
   }
   return -1;
}



int gpio_test(){
	gpio_list.sort();

	/* seting all gpio output mode with logic HIGH */
	for(auto i : gpio_list){

		GPIO obj(i);
		if(-1 == obj.setDirection(GPIO::DIRECTION::OUTPUT)){ return GPIO_DIRECTION_FAIL;}
		if(-1 == obj.setValue(GPIO::VALUE::HIGH)){ return GPIO_WRITE_FAIL;}

	}
	return 0;
}
