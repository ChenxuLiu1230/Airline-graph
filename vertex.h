#pragma once
#include <string>
using namespace std;

/** 
 * @brief The "vertex" class represents an airport on the flight graph.
 **/

class vertex {
    public:
        vertex();
        vertex(int airportID, string name, string IATA, string ICAO, double latitude, double longtitude);

        int airportID;
        string name;
        string IATA;
        string ICAO;
        double latitude;
        double longtitude;
        bool operator==(const vertex & other);
    

};