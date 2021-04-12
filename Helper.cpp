#include "Helper.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <sys/resource.h>
#include "readFromFile.hpp"
#include "country.h"
#include "airport.h"
#include <cmath>
using namespace std;






vector <Country> make_country_list(){
	ifstream fin("data/country.txt"); //open file
	string line; 
	vector <Country> CL;
	while (getline(fin, line))   //read entire line, 
	{
		string temp = line; //current line of text read in .txt file
		string delimiter ="\""; //text is seperated by " set delimiter
		size_t pos = 0;
		int counter= 0;
		string country;
		//find full name of the country in current line
		while ((pos = temp.find(delimiter)) != string::npos) {
    			counter++;
				if(counter%2 == 1) {//find first " and delete it
					temp.erase(0,pos+delimiter.length());
					continue; 
				}	
				else if(counter%8 ==2){ //find second ", going to output found string
					country = temp.substr(0, pos);
    				CL.push_back(Country(country));
    				temp.erase(0, pos + delimiter.length());
				} 				
		}
	}
	return CL;

}

// Test case for make_country_list() 
void test_country_list(vector <Country> l){
	for (size_t i = 0; i<50; i++){
		size_t temp = i+1;
		cout<<"The "<<temp<<" country is "<<l[i].name<<endl;
	}
	cout<<"total number of countries is "<<l.size()<<endl;
}


//helper function to initialize airports
/*
!!!!!!!!!!!!!!!
complete function, ask in wechat group before modifying
!!!!!!!!!!!!!!!
*/
vector <Airport> make_airport_list(){
	ifstream fin("data/airports.txt"); //open file
	string line; 
	vector <Airport> al;
	//make airports' index euqal to their ID
	Airport head = Airport();
	al.push_back(head);
	int id = 0;
	while (getline(fin, line))   //read entire line, 
	{

		string temp = line; //current line of text read in .txt file
		string delimiter =" \" "; //string text is seperated by " set delimiter
		size_t pos = 0;
		int counter= 0;
		string str;
		string delimiter1 = ","; //some int value are found through ","
		
		//get airport ID
		pos = temp.find(delimiter1);
		str = temp.substr(0,pos);
		stringstream ss(str);
		ss>>id; //convert string to int

		//get rest of the information
		string name, city, country, IATA, ICOA;
		double lat,lon;
		//find full name of the country in current line
		while ((pos = temp.find(delimiter)) != string::npos) {
    			counter++;
				if(counter%2 == 1) {//find first " and delete it
					temp.erase(0,pos+delimiter.length());
					continue; 
				}	
				//find second ", going to output found string
				else if( counter == 2){ //get airport's name
					str = temp.substr(0, pos);
    				name = str;
    				temp.erase(0, pos + delimiter.length());
				}
				else if( counter == 4){ //get airport's city
					str = temp.substr(0, pos);
    				city = str;
    				temp.erase(0, pos + delimiter.length());
				}	
				else if(counter == 6){ //get airport's country
					str = temp.substr(0, pos);
    				country = str;
    				temp.erase(0, pos + delimiter.length());
				}
				else if(counter == 8){ //get airport's IATA
					str = temp.substr(0, pos);
    				IATA = str;
    				temp.erase(0, pos + delimiter.length());
				}
				else if(counter == 10){ //get airport's ICOA
					str = temp.substr(0, pos);
    				ICOA = str;
    				temp.erase(0, pos + delimiter.length());

					//start to get coordinate
					int temp_counter = 0;
					while ((pos = temp.find(delimiter1)) != string::npos){
						temp_counter++;
						if(temp_counter == 2){ //find latitude
							str = temp.substr(0,pos);
							stringstream s1(str);
							s1>>lat;
							temp.erase(0, pos + delimiter.length());
						}
						else if(temp_counter == 3){//find longitude
							str = temp.substr(0,pos);
							stringstream s2(str);
							s2>>lon;
							temp.erase(0, pos + delimiter.length());
						}
						else{//erase unused string 
							temp.erase(0, pos + delimiter.length());
						}
					}
				}
		}
		//push airport into vector
		Airport temp_airport = Airport(id, name, IATA, ICOA, lat, lon);
		temp_airport.set_city(city);
		temp_airport.set_country(country);
		al.push_back(temp_airport);
	}
	return al;
}

// This implementation of havrrsine formula is referenced from https://www.movable-type.co.uk/scripts/latlong.html.
double distance(Airport * first, Airport * second) {
    double const PI = atan(1) * 4;   // 3.1415926...
    double const RADIUS = 6371;     // radius of the earth, km.
    double lat1 = first -> get_lat() * PI / 180;
    double lon1 = first -> get_lon() * PI / 180;
    double lat2 = second -> get_lat() * PI / 180;
    double lon2 = second -> get_lon() * PI / 180;
    double deltalat = (second -> get_lat() - first -> get_lat()) * PI / 180;
    double deltalon = (second -> get_lon() - first -> get_lon()) * PI / 180;
    double a = pow(sin(deltalat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltalon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return RADIUS * c;
}


//test case for make_airport_list()
//instruction in is the input airport vector, 
//n is the Unique ID of the airport, same as the line number in the txt file
void test_airport_list(vector <Airport> in, int n){
	in[n].info();	
}

//unused function that can increase stack size from 8MB to 16MB
void increase_stack_size(){
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }

}