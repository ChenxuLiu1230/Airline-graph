#include "airport.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @brief default constructor for airport (empty node)
**/
Airport::Airport() {
    airportID = 0;
    name = "This airport ID does not match any existing airport in the data base";
    IATA = "";
    ICAO = "";
    latitude = 0.0;
    longitude = 0.0;
    flag = false;
    vector<Airport*> a,b,d;
    vector<double> c,e,f;
    direct_destinations = a;
    indirect_destinations = b;
    weights = c;
    incoming_airports = d;
    incoming_distance = e;
    distance = f;
    distance.resize(14111,INT32_MAX);
}

/**
 * @brief : custom constructor for airport with the given information of airport.
 * @param : airport, name, IATA, ICAO, latitude, longtitude.
**/
Airport::Airport(int airportID, string name, string IATA, string ICAO, double latitude, double longitude, bool flag) 
    : airportID(airportID), name(name), IATA(IATA), ICAO(ICAO), latitude(latitude), longitude(longitude), flag(flag)
{

    vector<Airport*> a,b,d;
    vector<double> c,e,f;
    direct_destinations = a;
    indirect_destinations = b;
    weights = c;
    incoming_airports = d;
    incoming_distance = e;
    distance = f;
    distance.resize(14111,INT32_MAX);
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
vector <double> Airport::get_distance() const {return distance;}


// void Airport::info(){    
//     if(!flag){
//         cout<<name<<endl;
//     }else{
        
//         cout<< "\n ID: "<< airportID<<", "; 
// 	    cout<< "\n name: "<<name<<", ";
// 	    cout<< "\n city: "<<city<<", ";
// 	    cout<< "\n country: "<<country<<", ";
// 	    cout<< "\n latitude: "<<latitude<<", ";
// 	    cout<< "\n longitude: "<<longitude<<", ";
// 	    cout<< "\n IATA: "<<IATA<<", ";
// 	    cout<< "\n ICOA: "<<ICAO<<endl;
//     }
// }

ostream& operator<<(ostream& os, const Airport & source) {
    os << "\n ID: "<< source.airportID<<", "<<"\n name: "<<source.name <<"\n city: "<< source.city<<", "<<"\n country: "<<source.country<<", "
        <<"\n latitude: "<<source.latitude<<", "<<"\n longitude: "<<source.longitude<<", "<<"\n IATA: "<<source.IATA<<", "
        <<"\n ICAO: "<<source.ICAO<<endl;
    return os;
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

void Airport::add_distance(double in, int index){

    distance[index] = in;
}