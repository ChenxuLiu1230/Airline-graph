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
#include "graph.h"
#include "Helper.cpp" 
using namespace std;






int main()
{	

	// vector <Country> country_list = make_country_list();//initialize Country, 261 countries in total	
	// // test_country_list(country_list);//test case 

	// // test travese the airports array
	// vector <Airport> airport_list = make_airport_list();	
	// int start;
    // for (int i = 0; i < (int) airport_list.size(); i++) {
    //   if (airport_list[i].get_name() == "Melitopol Air Base") {
    //     start = i;
    //   }
    // }
	// cout << start << endl;


	// for (unsigned i = 0; i < airport_list.size(); i++) {
	// 	cout << airport_list[i].get_id() << endl;
	// }


	// vector <Country> country_list = make_country_list();//initialize Country, 261 countries in total	
	// test_country_list(country_list);//test case 
	// vector <Airport> airport_list = make_airport_list();	
	// for(size_t i =0; i<airport_list.size(); i++){
	// 	if(airport_list[i].get_id() == 0){
	// 		airport_list[i].set_id((int)i);
	// 	}
	// }
	// test_airport_list(airport_list,3774,5);//test case. instruction: second input is the index of the airport you want to check
	// read_routes(airport_list); 
	// test_read_routes(airport_list,3320);
	
	// //check destination vector 
	// cout<<check_overlap_2(airport_list,1)<<"\n"<<endl;

	// test BFS
	Graph testgraph;
	testgraph.BFS_all();
	// testgraph.BFS_id(1);
	//testgraph.BFS_id(1998);


	return 0;
}




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
