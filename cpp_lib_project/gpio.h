#ifndef GPIO_H
#define GPIO_H 

#include <stdint.h>
#include <string>
#include <fstream>

using namespace std;

class gpio
{
protected:
    uint16_t pin;
    string direction;

public:
    int8_t set_pin(uint16_t);
    int8_t set_direction(string);
    int8_t export_pin();
    int8_t unexport_pin();
    int8_t digital_write(bool);
    int8_t digital_read(bool &);
    int8_t get_direction();
    int8_t get_pin();
    ~gpio()
    {
        this->unexport_pin();
    }
};

#endif