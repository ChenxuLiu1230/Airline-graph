#pragma once
#include <vector>
#include <string>
#include "airport.h"
#include <fstream>
//#include "Helper.cpp"
using namespace std;
class Graph {
    public:
        Graph();
        void BFS_id(int start);
        void BFS_name(string name);
        void BFS_IATA(string IATA);
        void BFS_all();
        vector<int> shortestPath(int source, int destination);
        

    private:
        // this vector contains all the information of an airline graph
        // the airport is stored at index (airportID)
        vector<Airport> airports; 
        void BFS_helper(int start, ofstream & fout, vector<bool>& globalvisited);

        
    
        
};