#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include "readFromFile.hpp"
#include "country.h"
#include "airport.h"
using namespace std;

// int main(int argc, const char * argv[]) {
// 	std::cout << "Filename: " << argv[1] << std::endl;
	
// 	// convert file to string representation
// 	std::cout << "String Representation:" << std::endl;
// 	std::cout << file_to_string(argv[1]) << std::endl;
	
// 	// convert file to vector representation
// 	std::cout << "Vector Representation:" << std::endl;
// 	std::vector<std::string> vectorRepr = file_to_vector(argv[1]);
// 	for (auto word : vectorRepr) {
// 		std::cout << word << std::endl;
// 	}	
// }


//helper function to initialize Country List
/*
!!!!!!!!!!!!!!!
complete function, ask in wechat group before modifying
!!!!!!!!!!!!!!!
*/
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
//Test case for make_country_list()
void test_country_list(vector <Country> l){
	for (size_t i = 0; i<50; i++){
		size_t temp = i+1;
		cout<<"The "<<temp<<" country is "<<l[i].name<<endl;
	}
	cout<<"total number of countries is "<<l.size()<<endl;
}


//helper function to initialize airports
//not yet complete
void make_airport_list(){
	ifstream fin("data/test.txt"); //open file
	string line; 
	vector <Airport> al;
	while (getline(fin, line))   //read entire line, 
	{
		string temp = line; //current line of text read in .txt file
		string delimiter ="\""; //text is seperated by " set delimiter
		size_t pos = 0;
		int counter= 0;
		string str;

		//get airport ID
		str = temp.substr(0,1);
		int id;
		stringstream ss(str);
		ss>>id; //convert string to int
		cout<<"unique id is " <<id << endl;

		// variable to find coordinate
		string delimiter1 = ",";

		string name, city, country, IATA, ICOA;
		double lat,lon;
		//find full name of the country in current line
		while ((pos = temp.find(delimiter)) != string::npos) {
    			counter++;
				if(counter == 1) cout<<"index "<< pos<<endl;
				if(counter%2 == 1) {//find first " and delete it
					temp.erase(0,pos+delimiter.length());
					continue; 
				}	
				//find second ", going to output found string
				else if( counter == 2){ //get airport's name
					str = temp.substr(0, pos);
    				name = str;
					cout<<"name is " << name << endl;
    				temp.erase(0, pos + delimiter.length());
				}
				else if( counter == 4){ //get airport's city
					str = temp.substr(0, pos);
    				city = str;
					cout<<"city is " << city << endl;
    				temp.erase(0, pos + delimiter.length());
				}	
				else if(counter == 6){
					str = temp.substr(0, pos);
    				country = str;
					cout<<"country is " << country << endl;
    				temp.erase(0, pos + delimiter.length());
				}
				else if(counter == 8){
					str = temp.substr(0, pos);
    				IATA = str;
					cout<<"IATA is " << IATA << endl;
    				temp.erase(0, pos + delimiter.length());
				}
				else if(counter == 10){
					str = temp.substr(0, pos);
    				ICOA = str;
					cout<<"ICOA is " << ICOA << endl;
    				temp.erase(0, pos + delimiter.length());

					//start to get coordinate
					int temp_counter = 0;
					while ((pos = temp.find(delimiter1)) != string::npos){
						str = temp.substr(0,pos);
						stringstream s1(str);
						s1>>lat;
						cout <<"latitude is "<< lat <<endl;

					}
				}
		}
	}
}


int main()
{
	//initialize Country, 261 countries in total
	vector <Country> country_list = make_country_list();
	//test case 
	//test_country_list(country_list);

	//make_airport_list();


	return 0;
}