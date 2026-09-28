//This is car.cc
//NOTES:

#include "car.h"

// Increment the number of times the car has been moved

void car:: move()
{
    ++num_moves;
}

// Return the number of times car has been mvoed
int car::get_num_moves() const{
    return num_moves;
}
// Return to license plate
const std::string &car::get_license() const
{
    return license;
}

// Print the car information
std::ostream& operator<<(std::ostream& lhs, const car& rhs)
{
    lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";

    return lhs;
}