#include <string>
#include <fstream>
using namespace std;

/* abstract class of gpio */
class gpio_class
{
protected:
    uint16_t pin;
    string direction;

public:
    virtual int8_t set_pin(uint16_t) = 0;
    virtual int8_t set_direction(string) = 0;
    virtual int8_t export_pin() = 0;
    virtual int8_t unexport_pin() = 0;
    virtual int8_t digital_write(bool) = 0;
    virtual int8_t digital_read(bool &) = 0;
};

class rpi_gpio : public gpio_class
{
public:
    rpi_gpio(uint16_t a_pin, string a_direction)
    {
        this->set_pin(a_pin);
        this->set_direction(a_direction);
    }
    ~rpi_gpio()
    {
        this->unexport_pin();
    }
    int8_t set_pin(uint16_t arg_pin);
    int8_t set_direction(string str_dir);
    int8_t export_pin();
    int8_t unexport_pin();
    int8_t digital_write(bool data);
    int8_t digital_read(bool &data);
};
