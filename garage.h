//This is garage.h, 
// Defines the garage class and it's functions

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

#ifndef GARAGE_H
#define GARAGE_H

#include "car.h"

#include <cstddef>
#include <deque>
#include <string>

class garage
{
    public:
    //create garage with maximum limit of 10 cars
    garage(size_t limit = 10) : parking_lot_limit(limit) {}

    // process an arriving car
    void arrival(const std::string &license);

    // process a departing car
    void departure(const std::string &license);

    private:
        int next_car_id = {1}; // ID for next car that arrives
        std::deque<car> parking_lot; // deque used to store cars in garage
        size_t parking_lot_limit; // maximum number of cars allowed
};
#endif;