#include "vertex.h"
#include <string>

/**
 * @brief default constructor for vertex (empty node)
**/

vertex::vertex() {
    airportID = 0;
    name = "";
    IATA = "";
    ICAO = "";
    latitude = 0.0;
    longtitude = 0.0;
    
}

/**
 * @brief custom constructor for vertex with the given information of airport.
**/

vertex::vertex(int airportID, string name, string IATA, string ICAO, double latitude, double longtitude) 
    : airportID(airportID), name(name), IATA(IATA), ICAO(ICAO), latitude(latitude), longtitude(longtitude)
{
}

/**
 * @brief Overload == to compare whether two airports are the same.
**/

bool vertex::operator==(const vertex & other) {
    // the airportID uniquely represents an airport.
    if(this->airportID == other.airportID){
        return true;
    } else {
        return false;
    }
}