//This is car.cc
// Defines the car functions and it's information

//Header
//*****************************************************
// Name: Victoria Torres
// ZId:  Z2043396 
// CSCI 340 PE1
// Parking Garage Assignment, creates parking garage system using deque and
// stack to manage car arrivals and departures. 
// 9/29/2026 
//I certify that this is my own work and, where appropriate, an extension
// Of the starter code provided for the assignment.
//*****************************************************

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