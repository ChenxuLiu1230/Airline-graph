#pragma once
#include <string>
using namespace std;

/** 
 * @brief The "airport" class represents an airport on the flight graph.
 **/

class Airport {
    public:
        Airport();
        Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longtitude);

        int airportID;
        string name;
        string IATA;
        string ICAO;
        double latitude;
        double longtitude;
        bool operator==(const Airport & other);

        //added
        string city;
        string country;
    

};