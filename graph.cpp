
#include "graph.h"
#include "airport.h"
#include "Helper.h"
#include <queue>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
/**
 * @brief construct the whole airline graph.
**/
Graph::Graph() {
    airports = make_airport_list();
    read_routes(airports);   // at this point, the vector 'airports' contain all the flight information.
}


/**
 * @brief Breadth-first traversal of the graph.
 * @param : start, marks the airportID of the starting airport of the traversal.
**/
void Graph::BFS_id(int start) {
    queue<Airport*> container;   // used to do BFS.
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.
    ofstream fout;
    fout.open("bfs_output.txt");

    container.push(&airports[start]);
    visited[start] = true; 
    
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      vector<Airport*> destinations = curr -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
          visited[(*it) -> get_id()] = true;  
        }
      }
      container.pop();
      fout << curr -> get_name() << "->";
      // curr -> info();   // print relevant information of the airport to represent that this airport is visited.
      
    }
}

/**
 * @brief Breadth-first traversal of the graph.
 * @param : name, the name of the starting airport.
**/
void Graph::BFS_name(string name) {
    queue<Airport*> container;   // used to do BFS.
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.
    ofstream fout;
    fout.open("bfs_output.txt");

    int start;
    // traverse the airports array to find the right start airportID.
    for (int i = 0; i < (int) airports.size(); i++) {
      if (airports[i].get_name() == name) {
        start = i;
      }
    }
    container.push(&airports[start]);
    visited[start] = true; 
    
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      vector<Airport*> destinations = curr -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
          visited[(*it) -> get_id()] = true;  
        }
      }
      container.pop();
      fout << curr -> get_name() << "->";
      // curr -> info();   // print relevant information of the airport to represent that this airport is visited.
      
      
    }
    
}

/**
 * @brief Breadth-first traversal of the graph.
 * @param : IATA, the unique IATA code of the starting airport.
**/
void Graph::BFS_IATA(string IATA) {
    queue<Airport*> container;   // used to do BFS.
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.
    ofstream fout;
    fout.open("bfs_output.txt");

    int start;
    // traverse the airports array to find the right start airportID.
    for (int i = 0; i < (int) airports.size(); i++) {
      if (airports[i].get_IATA() == IATA) {
        start = i;
      }
    }
    container.push(&airports[start]);
    visited[start] = true; 
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      vector<Airport*> destinations = curr -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
          visited[(*it) -> get_id()] = true;  
        }
      }
      container.pop();
      fout << curr -> get_name() << "->";
      // curr -> info();   // print relevant information of the airport to represent that this airport is visited.
      
    }
    
}

/**
 * @brief Breadth-first traversal of all the connected components in the graph.
 * @return The output of the traversal is stored in a text file.
**/
void Graph::BFS_all() {
  ofstream fout;
  fout.open("bfs_all_output");
  vector<bool> globalvisited(airports.size(), false);
  for (int i = 0; i < (int) airports.size(); i++) {
    if (airports[i].valid() && !globalvisited[i]) {
      BFS_helper(i, fout, globalvisited);
    }
  }


}

/**
 * @brief Helper function to traverse all the connected components.
 * @param : start, marks the airportID of the starting airport of the traversal.
**/
void Graph::BFS_helper(int start, ofstream & fout, vector<bool>& globalvisited) {
    queue<Airport*> container;   // used to do BFS.
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.

    container.push(&airports[start]);
    visited[start] = true; 
    
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      vector<Airport*> destinations = curr -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
          visited[(*it) -> get_id()] = true;  
          globalvisited[(*it) -> get_id()] = true;
        }
      }
      container.pop();
      fout << curr -> get_id() << "->";
      // curr -> info();   // print relevant information of the airport to represent that this airport is visited.
      
    }
    fout << "\n";
}



/**
 * @brief Find the shortest path from the source to the destination airport, implemented by the Dijkstra's algorithm.
 * @param : source, the airportID of the source airport.
 * @param : destination, the airportID of the destination airport.
 * @return a sequence of airportID representing the shortest path found.
**/ 
vector<int> Graph::shortestPath(int source, int destination) {

}





