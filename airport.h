#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/** 
 * @brief The "airport" class represents an airport on the flight graph.
 **/

class Airport {
    public:
        Airport();
        Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude);

        
        bool operator==(const Airport & other);

        //newly added
        void set_id(int id_);
        void set_name(string name_);
        void set_IATA(string IATA_);
        void set_ICAO(string ICAO_);
        void set_lat(double lat);
        void set_lon(double lon);
        void set_city(string city_);
        void set_country(string country_);

        int get_id() const;
        double get_lat() const;
        double get_lon() const;
        string get_name() const;
        string get_IATA() const;
        string get_ICAO() const;
        string get_city() const;
        string get_country() const;
        
        void info();
        
        //newly added
    private:

        int airportID;
        string name;
        string IATA;
        string ICAO;
        double latitude;
        double longitude;
        string city;
        string country;

        // stores information about edges/routes
        // the elements of the two vectors at the same index represent the same airport.
        vector<Airport*> destinations; // stores a pointer to another airport which has some routes with the current airport.
        vector<double> weights;        // stores the corresponding distance, or edge weights.

};