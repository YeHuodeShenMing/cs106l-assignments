#include <string>


class Car {
    public:
        // constructor
        Car();
        Car(std::string name, std::string color, int wheel_nums);
        ~Car();

        int get_wheel_nums() const;
        void set_color(std::string new_color);
        

    private:
        std::string _name;
        std::string _color;
        int _wheel_nums;
        size_t nail_num;
        
        size_t size();
};