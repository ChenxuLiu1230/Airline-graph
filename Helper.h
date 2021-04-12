#pragma once
#include <vector>
#include "country.h"
#include "airport.h"
/**
 * @brief helper function to initialize Country List 
**/
vector <Country> make_country_list();

/**
 * @brief helper function to initialize airports
**/ 
vector <Airport> make_airport_list();

/**
 * @brief haversine formula for computing distance between two locations 
 *        given their latitude and longtitude.
**/ 
double distance(Airport * first, Airport * second);


