#include "studentID.h"
#include <string>

bool operator < (const studentID& self, const studentID& other) {
    return self.idNumber < other.idNumber;
}
