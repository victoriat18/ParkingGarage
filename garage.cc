//This is garage.cc
//NOTES:

#include "garage.h"

#include <iostream>
#include <stack>

// Process arriving car
void garage::arrival(const std::string &license)
{
    car new_car(next_car_id, license);
    std::cout << new_car << " has arrived." << std::endl;

    ++next_car_id;

    if (parking_lot.size() >= parking_lot_limit)
    {
        std::cout << "\tBut the garage is full!" << std::endl;
        std::cout << std::endl;
        return;
    }

    parking_lot.push_back(new_car);

    std::cout << std::endl;
}


// process departing car
void garage::departure(const std::string &license)
{
    std::stack<car> moved_cars;

    bool found = false;
    car departing_car(0, "");

    // move cars out of the way until we find the departing car
    while (!parking_lot.empty())
    {
        if (parking_lot.front().get_license() == license)
        {
            departing_car = parking_lot.front();
            parking_lot.pop_front();
            found = true;
            break;
        }

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

        return;
    }
    // Print departing car
    std::cout << departing_car << " has departed," << std::endl;

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

        moved_car.move();
        parking_lot.push_front(moved_car);
    }
    std::cout << std::endl;
}