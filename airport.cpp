#include "airport.h"
#include <string>

/**
 * @brief default constructor for airport (empty node)
**/

Airport::Airport() {
    airportID = 0;
    name = "";
    IATA = "";
    ICAO = "";
    latitude = 0.0;
    longtitude = 0.0;

    //newly added
    city = "";
    country = "";
    
}

/**
 * @brief custom constructor for airport with the given information of airport.
**/

Airport::Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longtitude) 
    : airportID(airportID), name(name), IATA(IATA), ICAO(ICAO), latitude(latitude), longtitude(longtitude)
{
}

/**
 * @brief Overload == to compare whether two airports are the same.
**/

bool Airport::operator==(const Airport & other) {
    // the airportID uniquely represents an airport.
    if(this->airportID == other.airportID){
        return true;
    } else {
        return false;
    }
}