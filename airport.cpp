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
    longitude = 0.0;

    //newly added
    city = "";
    country = "";
    
}

/**
 * @brief custom constructor for airport with the given information of airport.
**/

Airport::Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude) 
    : airportID(airportID), name(name), IATA(IATA), ICAO(ICAO), latitude(latitude), longitude(longitude)
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

//newly added
//set private variables
void Airport::set_id(int id_){
    airportID = id_;
}
void Airport::set_name(string name_){
    name = name_;
}
void Airport::set_IATA(string IATA_){
    IATA = IATA_;
}
void Airport::set_ICAO(string ICAO_){
    ICAO = ICAO_;
}
void Airport::set_lat(double lat){
    latitude = lat;
}
void Airport::set_lon(double lon){
    longitude = lon;
}
void Airport::set_city(string city_){
    city = city_;
}
void Airport::set_country(string country_){
    country = country_;
}
//return private variables

int Airport::get_id() {return airportID;}
double Airport::get_lat() {return latitude;}
double Airport::get_lon() {return longitude;}
string Airport::get_name() {return name;}
string Airport::get_IATA() {return IATA;}
string Airport::get_ICAO() {return ICAO;}
string Airport::get_city() {return city;}
string Airport::get_country() {return country;}

void Airport::info(){
    cout<< " ID is "<< airportID<<", "; 
	cout<< " name is "<<name<<", ";
	cout<< " city is "<<city<<", ";
	cout<< " country is "<<country<<", ";
	cout<< " latitude is "<<latitude<<", ";
	cout<< " longitude is "<<longitude<<", ";
	cout<< " IATA is "<<IATA<<", ";
	cout<< " ICOA is "<<ICAO<<endl;
}