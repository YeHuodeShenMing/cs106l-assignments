#include <string>

#include "car.h"

Car::Car()
{
    this->_color = "red";
    this->_name = "Ford";
    this->_wheel_nums = 4;
}

Car::Car(std::string name, std::string color, int wheel_nums)
{
    this->_name = name;
    this->_color = color;
    this->_wheel_nums = wheel_nums;
}

Car::~Car() {}

// public:
int Car::get_wheel_nums() const
{
    return this->_wheel_nums;
}

void Car::set_color(std::string new_color)
{
    this->_color = new_color;
}

// private:
size_t Car::size()
{
    return this->nail_num;
}
