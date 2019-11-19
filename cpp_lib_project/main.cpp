#include <iostream>
#include "gpio.h"
using namespace std;

int main()
{
    rpi_gpio out_pin(10, "out");
    rpi_gpio in_pin(11, "in");

    out_pin.digital_write(1);

    bool data = 0;
    in_pin.digital_read(data);
    cout << "read pin data : " << data << endl;

    while (1)
        ;
}
