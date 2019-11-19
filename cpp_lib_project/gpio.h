#include <string>
#include <fstream>
using namespace std;

enum error_no
{
    SUCCESS = 0,
    READ_FAIL = -1,
    WRITE_FAIL = -2,
};

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
        virtual int8_t analog_read(uint8_t &) = 0;
};

class rpi_gpio : public gpio_class
{
    public:
    rpi_gpio(uint16_t a_pin,string a_direction)
    {
        this->set_pin(a_pin);
        this->set_direction(direction);
    }
    ~ rpi_gpio()
    {
        this->unexport_pin();            
    }
    
    int8_t set_pin(uint16_t arg_pin)
    {
        pin = arg_pin;
        this->export_pin();
    }
    int8_t set_direction(string str_dir)
    {
        direction = str_dir;
        ofstream ofs; // output stream object
        string str_pin = to_string(this->pin);
        string pin_path = "/sys/class/gpio/gpio";
        pin_path += str_pin;
        pin_path += "direction";
        ofs.open(pin_path);
        if(direction == "out")
        {
            ofs.write("out",4);
        }
        else
        {
            ofs.write("in",3);
        }
        ofs.close();            
        return (SUCCESS);
    }

    int8_t export_pin()
    {
        ofstream ofs; // output stream object
        string str_pin = to_string(this->pin);
        ofs.open("/sys/class/gpio/export");
        ofs << str_pin;
        ofs.close();            
        return (SUCCESS);
    }
    int8_t unexport_pin()
    {
        ofstream ofs; // output stream object
        string str_pin = to_string(this->pin);
        ofs.open("/sys/class/gpio/unexport");
        ofs << str_pin;
        ofs.close();            
        return (SUCCESS);
    }
    int8_t digital_write(bool data)
    {
        ofstream ofs; // output stream object
        string str_pin = to_string(this->pin);
        string pin_path = "/sys/class/gpio/gpio";
        pin_path += str_pin;
        ofs.open(pin_path);
        if(data)
        {
            ofs.write("1",2);
        }
        else
        {
            ofs.write("0",2);
        }
        ofs.close();            
        return (SUCCESS);
    }
    int8_t digital_read(bool &data)
    {
        ifstream rfs;
        char read_data[2] = {0};
        string str_pin = to_string(this->pin);
        string pin_path = "/sys/class/gpio/gpio";
        pin_path += str_pin;
        rfs.open(pin_path);
        rfs.getline(read_data,2);
        if(read_data == "0")
        {
            data = 0;
        }
        else
        {
            data = 1;
        }
        return (SUCCESS);
    }
    int8_t analog_read(uint8_t &data)
    {
        /* read data from pin */
        data = 0;
        return (SUCCESS);
    }
};
