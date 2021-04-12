
#include "graph.h"
#include "airport.h"
#include "Helper.h"

/**
 * @brief construct the whole airline graph.
**/
Graph::Graph() {
    airports = make_airport_list();
    setUpRoutes();   
      // at this point, the vector 'airports' contain all the flight information.
}

/**
 * @brief set up routes information, modify the 
**/ 
void Graph::setUpRoutes() {
    
}

/**
 * @brief Breadth-first traversal of the graph.
**/
void Graph::BFS(int start) {
    
}

