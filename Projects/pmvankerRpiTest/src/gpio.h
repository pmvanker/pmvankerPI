/*
 * gpio.h
 *
 *  Created on: 13-May-2020
 *      Author: pmvanker
 */

#ifndef GPIO_H_
#define GPIO_H_

#include<string>
#include<fstream>
#include<sstream>
#include<string>
#include<list>
#include<unistd.h>

using std::string;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::list;
using std::stringstream;
using std::ostringstream;
#define GPIO_PATH "/sys/class/gpio/"

enum{
	GPIO_DIRECTION_FAIL = 1,
	GPIO_READ_FAIL,
	GPIO_WRITE_FAIL
};

/**
 * @class GPIO
 * @brief GPIO class for input and output functionality on a single GPIO pin
 */
class GPIO {
public:
	enum DIRECTION{ INPUT, OUTPUT };
	enum VALUE{ LOW=0, HIGH=1 };
	enum EDGE{ NONE, RISING, FALLING, BOTH };

private:
	int number;			/**< The GPIO number of the object */
	string name;		/**< The name of the GPIO e.g. gpio50 */
	string path;  		/**< The full path to the GPIO e.g. /sys/class/gpio/gpio50/ */

public:
	GPIO(int number);
	virtual int getNumber() { return number; } /**< Returns the GPIO number as an int. */

	// General Input and Output Settings
	virtual int setDirection(GPIO::DIRECTION);
	virtual GPIO::DIRECTION getDirection();
	virtual int setValue(GPIO::VALUE);
	virtual GPIO::VALUE getValue();
	virtual ~GPIO();  //destructor will unexport the pin

	// Advanced OUTPUT: Faster write by keeping the stream alive (~20X)
	virtual int streamOpen();
	virtual int streamWrite(GPIO::VALUE);
	virtual int streamClose();

private:
	int exportGPIO();
	int unexportGPIO();
	ofstream stream;
};


int write(string path, string filename, string value);
string read(string path, string filename);
int write(string path, string filename, int value);
int gpio_test();

#endif /* GPIO_H_ */
