#include "gpio.h"
enum error_no
{
    SUCCESS = 0,
    READ_FAIL = -1,
    WRITE_FAIL = -2,
};

int8_t rpi_gpio::set_pin(uint16_t arg_pin)
{
    pin = arg_pin;
    this->export_pin();
    return (SUCCESS);
}
int8_t rpi_gpio::set_direction(string str_dir)
{
    direction = str_dir;
    ofstream ofs; // output stream object
    string str_pin = to_string(this->pin);
    string pin_path = "/sys/class/gpio/gpio";
    pin_path += str_pin;
    pin_path += "/direction";
    ofs.open(pin_path);
    if (direction == "out")
    {
        ofs << "out";
    }
    else
    {
        ofs << "in";
    }
    ofs.close();
    return (SUCCESS);
}
int8_t rpi_gpio::export_pin()
{
    ofstream ofs; // output stream object
    string str_pin = to_string(this->pin);
    ofs.open("/sys/class/gpio/export");
    ofs << str_pin;
    ofs.close();
    return (SUCCESS);
}
int8_t rpi_gpio::unexport_pin()
{
    ofstream ofs; // output stream object
    string str_pin = to_string(this->pin);
    ofs.open("/sys/class/gpio/unexport");
    ofs << str_pin;
    ofs.close();
    return (SUCCESS);
}
int8_t rpi_gpio::digital_write(bool data)
{
    ofstream ofs; // output stream object
    string str_pin = to_string(this->pin);
    string pin_path = "/sys/class/gpio/gpio";
    pin_path += str_pin;
    pin_path += "/value";
    ofs.open(pin_path);
    if (data)
    {
        ofs << "1";
    }
    else
    {
        ofs << "0";
    }
    ofs.close();
    return (SUCCESS);
}
int8_t rpi_gpio::digital_read(bool &data)
{
    ifstream rfs;
    char read_data[2] = {0};
    string str_pin = to_string(this->pin);
    string pin_path = "/sys/class/gpio/gpio";
    pin_path += str_pin;
    pin_path += "/value";
    rfs.open(pin_path);
    rfs.getline(read_data, 2);
    if (read_data == "0")
    {
        data = 0;
    }
    else
    {
        data = 1;
    }
    return (SUCCESS);
}
