//This is garage.cc
// Manages car arrivals, departures, and parking spaces.

//HEADER
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



#include "garage.h"

#include <iostream>
#include <stack>

// Process arriving car
void garage::arrival(const std::string &license)
{
    // create a new car using next available ID
    car new_car(next_car_id, license);
    std::cout << new_car << " has arrived." << std::endl;
    // increase the id for the next arriving car
    ++next_car_id;
    // checking if garage is full
    if (parking_lot.size() >= parking_lot_limit)
    {
        std::cout << "\tBut the garage is full!" << std::endl;
        std::cout << std::endl;

        return;
    }
// add car to parking lot
    parking_lot.push_back(new_car);

    std::cout << std::endl;
}


// process departing car
void garage::departure(const std::string &license)
{
    // stack used to temporarily hold cars blocking departing car
    std::stack<car> moved_cars;

    bool found = false;
    car departing_car(0, "");

    // move cars out of the way until we find the departing car
    while (!parking_lot.empty())
    {
        //check if the car at the front is the one leaving
        if (parking_lot.front().get_license() == license)
        {
            departing_car = parking_lot.front();
            parking_lot.pop_front();
            found = true;
            break;
        }
        // move the blocking car from deque to stack
        car moved_car = parking_lot.front();
        parking_lot.pop_front();

        moved_cars.push(moved_car);
    }

    // The car was not found
    if (!found)
    {
        // Put moved cars back into original order
        while (!moved_cars.empty())
        {
            parking_lot.push_front(moved_cars.top());
            moved_cars.pop();
        }

        std::cout << "No car with license plate \"" << license
                  << "\" is in the garage." << std::endl;

        std::cout << std::endl; 

        return;
    }
    // Print departing car
    std::cout << departing_car << " has departed," << std::endl;
    // add 1 because departure itself counts as a move
    int total_moves = departing_car.get_num_moves() + 1;

    std::cout << "\tcar was moved " << total_moves;
    
    if (total_moves == 1)
    {
        std::cout << " time";
    }
    else
    {
        std::cout << " times";
    }

    std::cout << " in the garage." << std::endl;

    // Put the moved cars back into their original order
    while (!moved_cars.empty())
    {
        car moved_car = moved_cars.top();
        moved_cars.pop();

        //count this car as having been moved
        moved_car.move();
        // return the car to the fron of the deque
        parking_lot.push_front(moved_car);
    }
    std::cout << std::endl;
}