#pragma once
#include <string>
#include <iostream>
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

        int get_id();
        double get_lat();
        double get_lon();
        string get_name();
        string get_IATA();
        string get_ICAO();
        string get_city();
        string get_country();
        
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
    

};