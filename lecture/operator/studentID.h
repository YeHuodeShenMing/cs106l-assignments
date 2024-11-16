#include <string>

class studentID {
    private:
    std::string name;
    std::string sunet;
    int idNumber;

    public:
    friend bool operator < (const studentID& self, const studentID& other);
};