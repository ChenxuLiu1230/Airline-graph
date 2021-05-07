#include "Helper.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <sys/resource.h>
#include <algorithm>
#include "readFromFile.hpp"
#include "country.h"
#include "airport.h"
#include <cmath>
#include <algorithm>
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
*/
vector <Airport> make_airport_list(){
	ifstream fin("data/airports2.txt"); //open file
	string line; 
	vector <Airport> al;
	//make airports' index euqal to their ID
	Airport empty = Airport();
	al.push_back(empty);
	int id = 0;
	while (getline(fin, line))   //read entire line, 
	{		

		string temp = line; //current line of text read in .txt file
		string delimiter ="\""; //string text is seperated by " set delimiter
		size_t pos = 0;
		int counter= 0;
		string str;
		string delimiter1 = ","; //some int value are found through ","
		int flag  = 0;
		string delimiter2 = ",\"airport\"," ;

		//get airport ID
		pos = temp.find(delimiter1);
		str = temp.substr(0,pos);
		stringstream ss(str);
		ss>>id; //convert string to int

		//get rest of the information
		string name, city, country, IATA, ICOA;
		double lat,lon;

		if (temp.find(delimiter2) != std::string::npos) {
    		flag = 1;
		}

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
		//some airports are not found in given data base, for example 
		//there is no airport with ID 118 in the data base
		//also need to create space for such node
		int difference = id - (int)al.size();
		if(difference > 0){
			for(int i = difference; i>0; i--){
				al.push_back(empty);
			}
		}
		if(flag == 1){
		Airport temp_airport = Airport(id, name, IATA, ICOA, lat, lon, true);
		temp_airport.set_city(city);
		temp_airport.set_country(country);
		al.push_back(temp_airport);
		}
		
	}
	return al;
}

//test case for make_airport_list()
//instruction in is the input airport vector, 
//n and m are the Unique ID of the airport, same as the line number in the txt file
void test_airport_list(vector <Airport> & in, int n){
	cout<<"\nstart of test_airport_list"<<endl;
	cout<<"\nfirst input airport"<<endl;
	cout<<in[n];
}

void read_routes(vector <Airport> &in){
	ifstream fin("data/routes.txt"); //open file
	string line; 
	int indirect_num = 0;
	//cout<<"check1"<<endl;
	while (getline(fin, line))   //read entire line, 
	{
		//cout<<"check2"<<endl;
		string temp = line; //current line of text read in .txt file
		string delimiter =","; //text is seperated by " set delimiter
		string str;
		size_t pos = 0;
		int counter= 0;
		int source_id, dest_id;
		int stop;
		//find full name of the country in current line
		
		while ((pos = temp.find(delimiter)) != string::npos) {
    			counter++;
				if( counter == 4 ){
					str = temp.substr(0,pos);
					stringstream s1(str);
					s1>>source_id;
					temp.erase(0, pos + delimiter.length());
				}
				else if( counter == 6 ){
					str = temp.substr(0,pos);
					stringstream s2(str);
					s2>>dest_id;
					temp.erase(0, pos + delimiter.length());
				}
				else if( counter == 8){
					str = temp.substr(0,pos);
					stringstream s3(str);
					s3>>stop;
					temp.erase(0, pos + delimiter.length());
				}
				else{
					temp.erase(0, pos + delimiter.length());
				}							
		}		
		if(stop == 0){
			if(dest_id == 0 || source_id == 0 || in[dest_id].get_id() == 0 || in[source_id].get_id() == 0){
				//skip such line
			}
			else{
			in[source_id].add_dd(&in[dest_id]);		
			in[dest_id].add_inc(&in[source_id]);
			double dis;
			Airport * s = &in[source_id];
			Airport * d = &in[dest_id];
			dis = distance(s,d);
			in[source_id].add_weight(dis);//add dis to weight in source airport node
			in[dest_id].add_inc_dis(dis);// add dis to incoming_distance in destination airport node
			in[source_id].add_distance(dis,dest_id);
			}		
		}
		else if(stop > 0){
			indirect_num++;
			//if ( !check_overlap(in,source_id,dest_id) ) cout<<"indrect overlap"<<endl;
			//else 
			in[source_id].add_ind(&in[dest_id]);	
		}

	}
	// cout<<"\nnumber of routes with stop"<<indirect_num<<endl;

}

void test_read_routes(vector<Airport> & in, size_t n){
	cout<<"\nstart of test_read_routs"<<endl;
	vector <Airport*> temp,temp1;	
	vector<int> dd_visited;  		// used to check repeated nodes in destination list.
	vector<int> source_visited; 	// used to check repeated nodes in incoming list.
	int dd_size = 0;
	int source_size = 0;
	temp = in[n].get_dd();
	temp1 = in[n].get_inc();
	if(!in[n].valid()){
		cout<<in[n].get_name();
		return;
	}
	cout<<"The input airport is Airport "<<in[n].get_id()<<": "<<in[n].get_name()<<endl;
	cout<<"\ndestination list:"<<endl;
	for(size_t i=0; i<temp.size(); i++){
		if (count(dd_visited.begin(), dd_visited.end(), temp[i]->get_id())) {
			continue;
		}
		cout<<"Airport "<<temp[i]->get_id()<<": "<<temp[i]->get_name()<< endl;
		dd_visited.push_back(temp[i]->get_id());
		dd_size++;
	}

	cout<<"\nincoming source list:"<<endl;
	for(size_t i=0; i<temp1.size(); i++){
		if (count(source_visited.begin(), source_visited.end(), temp1[i]->get_id())) {
			continue;
		}
		cout<<"Airport "<<temp1[i]->get_id()<<": "<<temp1[i]->get_name()<< endl;
		source_visited.push_back(temp1[i]->get_id());
		source_size++;
	}
	cout<<"\n\nsize of destination list is: "<<dd_size<<"\nsize of current weights is: "<<dd_size<<endl;
	cout<<"\nsize of incoming list is: "<<source_size<<"\nsize of incoming distance is: "<<source_size<<endl;
	cout<<"\n";
	
}

// This implementation of havrrsine formula is referenced from https://www.movable-type.co.uk/scripts/latlong.html.
double distance(Airport * first, Airport * second) {
    double const PI = atan(1) * 4;   // 3.1415926...
    double const RADIUS = 6371;     // radius of the earth, km.
    double lat1 = first -> get_lat() * PI / 180;
    double lon1 = first -> get_lon();
    double lat2 = second -> get_lat() * PI / 180;
    double lon2 = second -> get_lon();
    double deltalat = (second -> get_lat() - first -> get_lat()) * PI / 180;
    double deltalon = (lon2-lon1) * PI / 180;
    double a = pow(sin(deltalat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltalon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return RADIUS * c;
}

bool check_overlap(vector <Airport> in, int a, int b){

	vector <Airport*> temp = in[a].get_dd();
	for(size_t i = 0; i<temp.size(); i++){
		if(temp[i]->get_id() == b) return false;
	}
	return true;
}

string check_overlap_2(vector <Airport> in, size_t n){
	vector <Airport*> temp1 = in[n].get_dd();
	int a,b;
	for(size_t i = 0; i<temp1.size(); i++){
		a = temp1[i]->get_id();
		for(size_t j = i+1; j<temp1.size(); j++){
			b = temp1[j]->get_id();
			if(a==b) return "there are overlap routes";
		}
	}
	return "all distinct routes";
}

int getIndex(vector<int> v, int K)
{

    for (size_t i = 0; i < v.size(); i++){
		if (v[i] == K) return (int)i;
	}
	cout<<"\n can't find such key "<<K<< " in the vector" <<endl;
 	return -1;    
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