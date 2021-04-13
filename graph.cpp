
#include "graph.h"
#include "airport.h"
#include "Helper.h"
#include <queue>
#include <vector>
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
void Graph::BFS(int start) {
    queue<Airport*> container;   // used to do BFS.
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.

    container.push(&airports[start]);
    visited[start] = true; 
    
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      for (auto it = curr -> get_dd().begin(); it != curr -> get_dd().end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
          visited[(*it) -> get_id()] = true;  
        }
      }
      container.pop();
      curr -> info();   // print relevant information of the airport to represent that this airport is visited.
    
    }
}

/**
 * @brief Find the shortest path from the source to the destination airport, implemented by the Dijkstra's algorithm.
 * @param : source, the airportID of the source airport.
 * @param : destination, the airportID of the destination airport.
 * @return a sequence of airportID representing the shortest path found.
**/ 
vector<int> Graph::shortestPath(int source, int destination) {

}




/**
 * @brief set up routes information, modify the 
**/ 
void Graph::setUpRoutes() {
    
}
