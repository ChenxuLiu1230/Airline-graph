#include "airport.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @brief default constructor for airport (empty node)
**/
Airport::Airport() {
    airportID = 0;
    name = "This airport node is empty, no such airport is found in data base";
    IATA = "";
    ICAO = "";
    latitude = 0.0;
    longitude = 0.0;
    flag = false;
    vector<Airport*> a,b,d;
    vector<double> c,e;
    direct_destinations = a;
    indirect_destinations = b;
    weights = c;
    incoming_airports = d;
    incoming_distance = e;
}

/**
 * @brief : custom constructor for airport with the given information of airport.
 * @param : airport, name, IATA, ICAO, latitude, longtitude.
**/
Airport::Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude, bool flag) 
    : airportID(airportID), name(name), IATA(IATA), ICAO(ICAO), latitude(latitude), longitude(longitude), flag(flag)
{

    vector<Airport*> a,b,d;
    vector<double> c,e;
    direct_destinations = a;
    indirect_destinations = b;
    weights = c;
    incoming_airports = d;
    incoming_distance = e;
}

/**
 * @brief Overload == to compare whether two airports are the same.
 * @param : constant reference of another Airport.
**/
bool Airport::operator==(const Airport & other) {
    // the airportID uniquely represents an airport.
    if(this->airportID == other.airportID){
        return true;
    } else {
        return false;
    }
}

/**
 * @brief public set functions.
**/
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
void Airport::set_dd(vector <Airport*> in) {direct_destinations = in; }
void Airport::set_id(vector <Airport*> in) {indirect_destinations = in; }
void Airport::set_weights(vector <double> in) {weights = in; }
void Airport::set_inc(vector <Airport*> in) {incoming_airports = in; }

/**
 * @brief public get functions.
**/
int Airport::get_id() const {return airportID;}
double Airport::get_lat() const {return latitude;}
double Airport::get_lon() const {return longitude;}
string Airport::get_name() const {return name;}
string Airport::get_IATA() const {return IATA;}
string Airport::get_ICAO() const {return ICAO;}
string Airport::get_city() const {return city;}
string Airport::get_country() const {return country;}
bool Airport::valid() const {return flag;};
vector <Airport*> Airport::get_dd() const {return direct_destinations;}
vector <Airport*> Airport::get_ind() const {return indirect_destinations;}
vector <double> Airport::get_weights() const {return weights;}
vector <Airport*> Airport::get_inc() const {return incoming_airports;}
vector <double> Airport::get_inc_dis() const {return incoming_distance;}

// could replace this by overloading the "<<" operator of the Airport class.
void Airport::info(){    
    if(!flag){
        cout<<name<<endl;
    }else{
        cout<<airportID<<" th ariport info: "<<endl;
        cout<< " ID is "<< airportID<<", "; 
	    cout<< " name is "<<name<<", ";
	    cout<< " city is "<<city<<", ";
	    cout<< " country is "<<country<<", ";
	    cout<< " latitude is "<<latitude<<", ";
	    cout<< " longitude is "<<longitude<<", ";
	    cout<< " IATA is "<<IATA<<", ";
	    cout<< " ICOA is "<<ICAO<<endl;
    }
}

void Airport::add_dd(Airport* in){

    Airport * temp = in;
    direct_destinations.push_back(temp);
    
}
void Airport::add_ind(Airport* in){

    Airport * temp = in;
    indirect_destinations.push_back(temp);
  
}
void Airport::add_weight(double in){

    double temp = in;
    weights.push_back(temp);
}
void Airport::add_inc(Airport* in){

    Airport * temp = in;
    incoming_airports.push_back(temp);
  
}
void Airport::add_inc_dis(double in){

    double temp = in;
    incoming_distance.push_back(temp);
}