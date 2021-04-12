#pragma once
#include <vector>
#include "Airport.h"
#include "Helper.h"
using namespace std;
class Graph {
    public:
        Graph();
        void BFS(int start);
        void setUpRoutes();    // insert routes information, modify the elements of the 'airports' vector.

    private:
        // this vector contains all the information of an airline graph
        // the airport is stored at index (airportID - 1)
        vector<Airport> airports; 
        
    
        
};