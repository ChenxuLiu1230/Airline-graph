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
        Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude, bool flag);

        
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
        void set_dd(vector <Airport*> in);
        void set_id(vector <Airport*> in);
        void set_weights(vector <double> in);

        int get_id() const;
        double get_lat() const;
        double get_lon() const;
        string get_name() const;
        string get_IATA() const;
        string get_ICAO() const;
        string get_city() const;
        string get_country() const;
        vector <Airport*> get_dd() const;
        vector <Airport*> get_ind() const;
        vector <double> get_weights() const;
        
        void info();//print information of current airport
        void add_dd(Airport* in);
        void add_ind(Airport* in);
        void add_weight(double in);

    private:
      
        
        int airportID;
        string name;
        string IATA;
        string ICAO;
        double latitude;
        double longitude;
        string city;
        string country;
        bool flag;  //check exsistence

        // stores information about edges/routes
        // the elements of the two vectors at the same index represent the same airport.
        vector<Airport*> direct_destinations; // stores a pointer to another airport which has some routes with the current airport.
        vector<Airport*> indirect_destinations; //stores pointrer to another airport that needs to stop
        vector<double> weights;        // stores the corresponding distance, or edge weights.

};