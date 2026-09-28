//This is car.h,
// Defines the car class and it's information

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



#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class car
{
    public:
    car(int id, const std::string &license) : id(id), license(license) {}
    // increment the numbr of times that car has been moved
    void move();

    int get_num_moves() const;

    const std::string &get_license() const;

    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs);
    
    private:
    int id;                // ID number for car
    std::string license;  // license plate of this car
    int num_moves = {0}; // how many times car has been moved
};

#endif;