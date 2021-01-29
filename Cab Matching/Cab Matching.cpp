// Cab Matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <vector>
#include"Matcher.h"

const vector<std::string>availableOptions = {
    "Add a ride",
    "Get Matching driver",
    "Exit"                  // always last option

};

void PrintMenu()
{
    cout << "=============Cab Matching====================\n";
    cout << "============= Available Options =============\n";
    for( int iCnt = 0; iCnt < availableOptions.size(); ++iCnt )
    {
        cout << iCnt+1 << ". " << availableOptions[iCnt] << " \n";
    }
}


void PerformAddRide(Matcher& matcher)
{
    std::string driverName, riderName;
    double riderRating, driverRating;
    std::cout << "Rider details===== \n";
    std::cout << "Rider Name: ";
    cin >> riderName;

    std::cout << "Rider rating: ";
    cin >> riderRating;

    std::cout << "Driver details===== \n";
    std::cout << "Driver Name: ";
    cin >> driverName;

    std::cout << "Driver rating: ";
    cin >> driverRating;

    matcher.AddRideDetails( riderName, riderRating, driverName, driverRating );
}


std::string PerformGetMatchingDriver( Matcher& matcher )
{
    std::string riderName;
    std::string driveName;

    std::cout << "Rider name: ";
    cin >> riderName;

    driveName = matcher.GetMatchingDriverName( riderName );
    return driveName;
}

int main()
{
    
    Matcher matcher;
    int option=0;
    do
    {
        PrintMenu();
        std::cout << "Enter choice: ";
        cin >> option;

        switch( option )
        {
            case 1:
            {
                PerformAddRide(matcher);
                break;
            }

            case 2:
            {
                const std::string driverName = PerformGetMatchingDriver(matcher);
                std::cout << "Driver: " << driverName << "\n";
                break;
            }

            case 3:
            {
                break;
            }
            default:
            {
                cout << "Invalid option. Enter [1:" << availableOptions.size() << "]" << std::endl;
                break;
            }
        }

    } while( option != availableOptions.size() );
    
}
