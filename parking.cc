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

//This is parking.cc
//Reads parking transactions and processes arrivals and departures.

#include "garage.h"

#include <iostream>
#include <string>

// get the tranasaction type & license plate from input line

void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    // Get the first character (A or D)
    xact_type = line[0];

    // find the colons that separate the transaction & license
    size_t first_colon = line.find(':');
    size_t second_colon = line.find(':', first_colon + 1);

    // extract license plate between colons
    license = line.substr(first_colon + 1, second_colon - first_colon - 1);

}

//Main
int main()
{
    // create the parking garage
    garage parking_garage;

    std::string line;
    // read each transaction line from input
    while (std::getline(std::cin, line))
{
    // process an arriving car
    char xact_type;
    std::string license;

    get_input_vals(line, xact_type, license);

    if (xact_type == 'A')
    {
        parking_garage.arrival(license);
    }
    // process departing car
    else if (xact_type == 'D')
    {
        parking_garage.departure(license);
    }
    else{
        // handle invalid transaction
        std::cout << "'" << xact_type << "': invalid action!" << std::endl;
        std::cout << std::endl;
    }
}

return 0;
}

