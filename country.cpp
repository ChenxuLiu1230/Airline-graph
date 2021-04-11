#include <string>
#include <vector>
#include "country.h"


using std::string;
using std::vector;

Country::Country(){
    name = "";
}

Country::Country(string country_name){
    name = country_name;
}


//Country(string country_name, string city_name);