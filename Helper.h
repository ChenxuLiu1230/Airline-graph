#ifndef Helper_H
#define Helper_H


#include <vector>
#include "country.h"
#include "airport.h"




/**
 * @brief helper function to initialize Country List
 * @return the created list of countries
**/
vector <Country> make_country_list();

/**
 * @brief test function that verify make_country_list(), check if the list is created successfully
 * @param l, the created list of country
**/ 
void test_country_list(vector <Country> l);

/**
 * @brief helper function to initialize airports
 * @return the created list of airports
**/ 
vector <Airport> make_airport_list();

/**
 * @brief test function that verify make_airport_list()
 * @param in the input list of airports
 * @param n the id of tested airport
**/ 
void test_airport_list(vector <Airport> & in, int n);

/**
 * @brief helper function to initialize routes
 * @param in the input list of airport
**/ 
void read_routes(vector <Airport> &in);

/**
 * @brief test function that verify readd_routes, can be modified freely
 * @param in is input airport vector  
 * @param n is the nth airport you want to test
**/ 
void test_read_routes(vector <Airport> & in, size_t n);

/**
 * @brief haversine formula for computing distance between two locations 
 *        given their latitude and longtitude.
 * @param first, one of the airports 
 * @param second, the other airport
 * @return the distance bewteen two airports
**/ 
double distance(Airport * first, Airport * second);



//   Below are helper functions that are optional to use. 
//   So the @param is omitted for simplicity
//   Users can discover these functions on their own

/**
 * @brief check if the second id has been included in first id's destination
 * return ture if there is no overlap, return false if there is overlap
**/ 
bool check_overlap(vector <Airport> in, int a, int b);


/**
 * @brief check if there is overlap routes in nth airport in the input vector
**/ 
string check_overlap_2(vector <Airport> in, size_t n);

/**
 * @brief function that find element's index in vector
**/ 
int getIndex(vector<int> v, int K);

/**
 * @brief function that can increase stack size if needed
**/ 
void increase_stack_size();

#endif