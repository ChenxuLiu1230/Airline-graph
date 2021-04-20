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
        void set_inc(vector <Airport*> in);

        int get_id() const;
        double get_lat() const;
        double get_lon() const;
        string get_name() const;
        string get_IATA() const;
        string get_ICAO() const;
        string get_city() const;
        string get_country() const;
        bool valid() const;  // check whether the current airport is really a valid airport.
        vector <Airport*> get_dd() const;
        vector <Airport*> get_ind() const;
        vector <double> get_weights() const;
        vector <Airport*> get_inc() const;
        vector <double> get_inc_dis() const;
        vector <double> get_distance() const;
        
        void info();//print information of current airport
        void add_dd(Airport* in);
        void add_ind(Airport* in);
        void add_weight(double in);
        void add_inc(Airport* in);
        void add_inc_dis(double in);
        void add_distance(double in, int index);

        

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
        vector<Airport*> indirect_destinations; //stores pointer to another airport that needs to stop
        vector<double> weights;        // stores the corresponding distance of direct_destnation, or edge weights.
        vector<Airport*> incoming_airports; // stores a poiner vector of all the airports that can come to this airport in routes.txt
        vector<double> incoming_distance; // stores distance from current airport to incoming airports
        vector<double> distance; //stores distance from this->airport to its destinations, index corresponds to their airportID
};