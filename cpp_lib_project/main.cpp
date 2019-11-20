#include <iostream>
#include <time.h>
#include "gpio.h"
using namespace std;

int main()
{
    gpio out_pin;
    gpio in_pin;

    out_pin.digital_write(1);

    bool data = 0;
    in_pin.digital_read(data);
    cout << "read pin data : " << data << endl;

    while (1)
        ;
}
