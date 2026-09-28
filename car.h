//This is car.h,
//NOTES:


#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class car
{
    public:
    car(int id, const std::string &license) : id(id), license(license) {}
//increment the numbr of times that car has been moved
    void move();

    int get_num_moves() const;

    const std::string &get_license() const;

    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs);
    
    private:
    int id;                // ID number for car
    std::string license;  // license plat of this car
    int num_moves = {0}; // how many times car has been moves
};

#endif