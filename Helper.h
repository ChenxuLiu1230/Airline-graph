#ifndef Helper_H
#define Helper_H


#include <vector>
#include "country.h"
#include "airport.h"




/**
 * @brief helper function to initialize Country List
**/
vector <Country> make_country_list();

/**
 * @brief test function that verify make_country_list(), can be modified freely
**/ 
void test_country_list(vector <Country> l);

/**
 * @brief helper function to initialize airports
**/ 
vector <Airport> make_airport_list();

/**
 * @brief test function that verify make_airport_list(), cna be modified freely
 * n and m are the nth and mth airports you want to test
**/ 
void test_airport_list(vector <Airport> & in, int n);

/**
 * @brief helper function to initialize routes, in is airport vector
**/ 
void read_routes(vector <Airport> &in);

/**
 * @brief test function that verify readd_routes, can be modified freely
 * in is input airport vector while n is the nth airport you want to test
**/ 
void test_read_routes(vector <Airport> & in, size_t n);

/**
 * @brief haversine formula for computing distance between two locations 
 *        given their latitude and longtitude.
**/ 
double distance(Airport * first, Airport * second);

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