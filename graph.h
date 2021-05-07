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
        void BFS_all();                     //BFS
        vector<bool> BFS_all_check();      // used for BFS sanity check.
        vector<int> shortestPath(int source, int destination);//use Dijkastra to find shortes path
        bool checkvalid(int in);
        vector<Airport> get_airports();
        vector<int> Dijkastra(int source);  //Dijkastra
        void bc(int source);                 //Betweeness Centrality
        int bc_check(int source);      // used for test case for betweenness centrality.
        

    private:
        // this vector contains all the information of an airline graph
        // the airport is stored at index (airportID)
        vector<Airport> airports; 
        void BFS_helper(int start, ofstream & fout, vector<bool>& globalvisited);

        
    
        
};