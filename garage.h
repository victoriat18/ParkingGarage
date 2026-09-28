//This is garage.h
//NOTES:

#ifndef GARAGE_H
#define GARAGE_H

#include "car.h"

#include <cstddef>
#include <deque>
#include <string>

class garage
{
    public:
    garage(size_t limit = 10) : parking_lot_limit(limit) {}
    // process an arriving car
    void arrival(const std::string &license);

    // process a departing car
    void departure(const std::string &license);

    private:
        int next_car_id = {1};
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};
#endif