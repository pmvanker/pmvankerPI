#include <iostream>
#include "gpio.h"
using namespace std;
int main()
{
    rpi_gpio uart_led(10,"out");
    rpi_gpio uart_led(11,"in");
    
    while(1);
}