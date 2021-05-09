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

        /**
         * @brief Default constructor for Airport class, used to create an "empty" or "invalid" airport.
        **/
        Airport();


        /**
         * @brief Customer constructor for Airport class, specifiying valid ID, name, IATA, etc.
         * @param : airportID, the ID of the airport.
         * @param : name, the name of the airport.
         * @param : IATA, the IATA of the airport.
         * @param : ICAO, the ICAO of the airport.
         * @param : latitude, the latitude of the airport location.
         * @param : longitude, the longitude of the airport location.
        **/
        Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude, bool flag);


        /**
         * @brief Overload == to compare whether two airports are the same.
         * @param : constant reference of another Airport.
         * @return true if the two airports nodes are exactly the same, false otherwise.
        **/
        bool operator==(const Airport & other);


        /**
         * @brief Overload << in order to print out relevant information of an airport.
         * @param : os, the ouput stream
         * @param : source, a constant reference to the airport whose information is to be printed.
         * @return the output stream of the airport information.
        **/
        friend ostream& operator<<(ostream& os, const Airport & source);


        /**
         * @brief set the airport ID for this airport.
         * @param : id_, integer ID of the airport.
        **/
        void set_id(int id_);


        /**
         * @brief set the name for this airport.
         * @param : name_, the string representing the name of the airport.
        **/
        void set_name(string name_);


        /**
         * @brief set the IATA for this airport.
         * @param : IATA_, the IATA of the airport used by OpenFlights.
        **/
        void set_IATA(string IATA_);


        /**
         * @brief set the ICAO for this airport.
         * @param : ICAO_, the ICAO of the airport used by OpenFlights.
        **/
        void set_ICAO(string ICAO_);


        /**
         * @brief set the latitude for this airport.
         * @param : lat, the latitude of this airport.
        **/
        void set_lat(double lat);


        /**
         * @brief set the longitude for this airport.
         * @param : lon, the longitude of this airport.
        **/
        void set_lon(double lon);


        /**
         * @brief set the city for this airport.
         * @param : city_, the city of this airport.
        **/
        void set_city(string city_);


        /**
         * @brief set the country for this airport.
         * @param : country_, the country of this airport.
        **/
        void set_country(string country_);


        /**
         * @brief set the direct destinations (directly connected) for this airport.
         * @param : in, the vector storing pointers to the direct destination airports.
        **/
        void set_dd(vector <Airport*> in);


        /**
         * @brief set the indirect destinations (indirectly connected) for this airport.
         * @param : in, the vector storing pointers to the indirect destination airports.
        **/
        void set_id(vector <Airport*> in);


        /**
         * @brief set the corresponding distances (weights) for this airport.
         * @param : in, the vector storing pointers to the direct destination airports.
        **/
        void set_weights(vector <double> in);


        /**
         * @brief set the incoming source airports for this airport.
         * @param : in, the vector storing pointers to the incoming source airports of this airport.
        **/
        void set_inc(vector <Airport*> in);


        /**
         * @brief get the id of this airport.
         * @return the id of this airport.
        **/
        int get_id() const;


        /**
         * @brief get the latitude of this airport.
         * @return the latitude of this airport.
        **/
        double get_lat() const;


        /**
         * @brief get the longitude of this airport.
         * @return the longitude of this airport.
        **/
        double get_lon() const;


        /**
         * @brief get the name of this airport.
         * @return the name of this airport.
        **/
        string get_name() const;


        /**
         * @brief get the IATA of this airport.
         * @return the IATA of this airport.
        **/
        string get_IATA() const;


        /**
         * @brief get the ICAO of this airport.
         * @return the ICAO of this airport.
        **/
        string get_ICAO() const;


        /**
         * @brief get the city of this airport.
         * @return the city of this airport.
        **/
        string get_city() const;


        /**
         * @brief get the country of this airport.
         * @return the country of this airport.
        **/
        string get_country() const;


        /**
         * @brief check whether the current airport is really a valid airport.
         * @return true if the airport is valid, false otherwise.
        **/
        bool valid() const;  


        /**
         * @brief get the direct destinations of this airport.
         * @return the vector storing pointers to the direct destinations airports of this airport.
        **/        
        vector <Airport*> get_dd() const;


        /**
         * @brief get the indirect destinations of this airport.
         * @return the vector storing pointers to the indirect destinations airports of this airport.
        **/           
        vector <Airport*> get_ind() const;


        /**
         * @brief get the distances(weights) between this airport and its direct destination airports.
         * @return the vector of distances.
        **/           
        vector <double> get_weights() const;


        /**
         * @brief get the incoming source airports of this airport.
         * @return the vector storing pointers to the incoming source airports of this airport.
        **/          
        vector <Airport*> get_inc() const;


         /**
         * @brief get the distances(weights) between this airport and its incoming source airports.
         * @return the vector of distances.
        **/             
        vector <double> get_inc_dis() const;



        vector <double> get_distance() const;
        

        /**
         * @brief helper function to add direct destinations.
         * @param : in, the pointer pointing to this direct destination.
        **/
        void add_dd(Airport* in);


        /**
         * @brief helper function to add indirect destinations.
         * @param : in, the pointer pointing to this indirect destination.
        **/
        void add_ind(Airport* in);


        /**
         * @brief helper function to set up distances.
         * @param : in, the distance.
        **/       
        void add_weight(double in);


        /**
         * @brief helper function to add incoming source airports.
         * @param : in, the pointer pointing to this incoming source airport.
        **/        
        void add_inc(Airport* in);


        /**
         * @brief helper function to set up distances between incoming source and this airport.
         * @param : in, the distance.
        **/            
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
        bool flag;  //check exsistence, true if the airport object is indeed a valid airport node.

        // Stores information about edges/routes
        // The elements of relevant two vectors (e.g., direct_destinations and weights) at the same index represent the same airport.

        // Stores a pointer to another airport which has some routes with the current airport.
        vector<Airport*> direct_destinations; 

        // Stores pointer to another airport that needs to stop.
        vector<Airport*> indirect_destinations; 

        // Stores the corresponding distance of direct_destnation, or edge weights.
        vector<double> weights;   

        // Stores a poiner vector of all the airports that can come to this airport in routes.txt
        vector<Airport*> incoming_airports; 

        // Stores distance from current airport to incoming airports.
        vector<double> incoming_distance;

        // Stores distance from this->airport to its destinations, index corresponds to their airportID
        vector<double> distance; 

        
};