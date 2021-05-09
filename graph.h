#pragma once
#include <vector>
#include <string>
#include "airport.h"
#include <fstream>
//#include "Helper.cpp"
using namespace std;
class Graph {
    public:


        /**
         * @brief Constructor for creating the whole flight graph. We read airports and routes information
         * into the graph, and once the constructor is called, all the information needed to explore this flight 
         * graph has been included in this Graph object.
        **/    
        Graph();


        /**
         * @brief Breadth-first traversal of the graph.
         * @param : start, the airportID of the starting airport of the traversal.
         * @return The result of the BFS is stored in output/bfs_output.txt.
        **/
        void BFS_id(int start);


        /**
         * @brief Breadth-first traversal of the graph.
         * @param : name, the name of the starting airport.
         * @return The result of the BFS is stored in output/bfs_output.txt.
        **/        
        void BFS_name(string name);


        /**
         * @brief Breadth-first traversal of the graph.
         * @param : IATA, the unique IATA code of the starting airport.
         * @return The result of the BFS is stored in output/bfs_output.txt.
        **/        
        void BFS_IATA(string IATA);


        /**
         * @brief Breadth-first traversal of all the connected components in the graph.
         * @return The output of the traversal is stored in a text file.
         * @return The result of the BFS on the whole graph is stored in output/bfs_all_output.
        **/
        void BFS_all();         


        /**
         * @brief Used for BFS sanity check.
         * @return the vector tracking whether each of the airport node has been visited.
        **/           
        vector<bool> BFS_all_check();      


        /**
         * @brief Find the shortest path from the source to the destination airport, implemented by the Dijkstra's algorithm.
         * @param : source, the airportID of the source airport.
         * @param : destination, the airportID of the destination airport.
         * @return a sequence of airportID representing the shortest path found.
        **/ 
        vector<int> shortestPath(int source, int destination);



        bool checkvalid(int in);


        /**
         * @brief Get the airports vector of the whole graph.
         * @return the vector of all the airports in the graph.
        **/          
        vector<Airport> get_airports();


        /**
         * @brief Helper function that calculates shortest paths used for betweenness centrality.
         * @param : source, the airportID of the source airport.
         * @return shortest path from the source airport to all the other airports (if reachable) in the graph.
        **/         
        vector<int> Dijkastra(int source);  


        /**
         * @brief Find the airport with the largest betweenness centrality with respect to a source node.
         * @param : source, the airportID of the source airport.
         * @return print out relevant information of the most "important" stop with the largest betweenness centrality.
        **/ 
        void bc(int source);   


        /**
         * @brief Test function for bc
         * @param : source, the airportID of the source airport.
         * @return the airport node with the largest bc wpt to the source node.
        **/               
        int bc_check(int source);      
        

    private:
        // this vector contains all the information of the airline graph
        // the airport is stored at index (airportID)
        vector<Airport> airports; 

        /**
         * @brief Helper function to traverse all the connected components.
         * @param : start, marks the airportID of the starting airport of the traversal.
         * @param : fout, the output stream used to write to the txt file.
         * @param : globalvisited, a reference to the vector keeping track of whether an airport node has been visited or not.
        **/
        void BFS_helper(int start, ofstream & fout, vector<bool>& globalvisited);

        
    
        
};