#ifndef Helper_H
#define Helper_H


#include <vector>
#include "country.h"
#include "airport.h"




/**
 * @brief helper function to initialize Country List 
**/
vector <Country> make_country_list();

void test_country_list(vector <Country> l);

/**
 * @brief helper function to initialize airports
**/ 
vector <Airport> make_airport_list();

void test_airport_list(vector <Airport> in, int n);

/**
 * @brief haversine formula for computing distance between two locations 
 *        given their latitude and longtitude.
**/ 
double distance(Airport * first, Airport * second);

void increase_stack_size();

#endif