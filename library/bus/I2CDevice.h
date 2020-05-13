/*
 * Created on: 13-May-2020
 *      Author: pmvanker
 */

#ifndef I2C_H_
#define I2C_H_

#define PI_I2C_0 "/dev/i2c-0"
#define PI_I2C_1 "/dev/i2c-1"

namespace pmvankerPI{

/**
 * @class I2CDevice
 * @brief Generic I2C Device class that can be used to connect to any type of I2C device and read or write to its registers
 */
class I2CDevice{
	unsigned int bus;    /**< the bus number */
	unsigned int device; /**< the device number on the bus  */
	int file;            /**< the file handle to the device */

public:
	I2CDevice(unsigned int bus, unsigned int device);
	virtual int open();
	virtual int write(unsigned char value);
	virtual unsigned char readRegister(unsigned int registerAddress);
	virtual unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0);
	virtual int writeRegister(unsigned int registerAddress, unsigned char value);
	virtual void debugDumpRegisters(unsigned int number = 0xff);
	virtual void close();
	virtual ~I2CDevice();
};

} /* namespace pmvankerPI */

#endif /* I2C_H_ */
