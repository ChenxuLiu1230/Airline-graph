
#include "graph.h"
#include "airport.h"
#include "Helper.h"
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
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
    fout.open("output/bfs_output.txt");
    int count = 0;

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
      fout << curr -> get_name();
      fout << "->";
      count++;
      if (count == 8) {
        fout << "\n";
        count = 0;
      }
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
    fout.open("output/bfs_output.txt");
    int count = 0;
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
      fout << curr -> get_name();
      fout << "->";
      count++;
      if (count == 8) {
        fout << "\n";
        count = 0;
      }
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
    fout.open("output/bfs_output.txt");
    int count = 0;
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
      fout << curr -> get_name();
      fout << "->";
      count++;
      if (count == 8) {
        fout << "\n";
        count = 0;
      }
      // curr -> info();   // print relevant information of the airport to represent that this airport is visited.
      
    }
    
}

/**
 * @brief Breadth-first traversal of all the connected components in the graph.
 * @return The output of the traversal is stored in a text file.
**/
void Graph::BFS_all() {
  ofstream fout;
  fout.open("output/bfs_all_output");
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
    int count = 0;

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
      if(curr->get_id() <10) fout <<"    " <<curr -> get_id();
      else if(curr->get_id() <100) fout <<"   " <<curr -> get_id();
      else if( curr->get_id() <1000) fout <<"  " <<curr -> get_id();
      else if(curr->get_id()<10000) fout <<" " <<curr -> get_id();
      else fout <<"" <<curr -> get_id();
      
      fout << "->";
      count++;
      if (count == 25) {
        fout << "\n";
        count = 0;
      }
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
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.
    vector<int> parents(airports.size(), -1); // keep track of each airport's parent node.
    vector<int> dist(airports.size(), INT32_MAX); // keep track of the minimum distance from source to this one.
    vector<int> ans{};
    dist[source] = 0;
    for (size_t count = 0; count < airports.size() - 1; count++) {
      int temp_air_idx, temp_min=INT32_MAX;
      for (size_t i = 0; i < dist.size(); i++) {
        if (!visited[i]) {
          if (dist[i] < temp_min) {
            temp_min = dist[i];
            temp_air_idx = i;
          }
        }
      }
      visited[temp_air_idx] = false;
      Airport* temp_airport = &airports[temp_air_idx];
      vector<Airport*> destinations = temp_airport -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!visited[(*it) -> get_id()]) {
          vector<Airport*> befores = (*it) -> get_inc();
          vector <double> distances = (*it) -> get_inc_dis();
          double temp_distance;
          for (size_t index=0; index < befores.size(); index++) {
              if ((befores[index] -> get_id()) == (temp_airport -> get_id())) {
                  temp_distance = distances[index];
              }
          }
          if (dist[(*it) -> get_id()] > (dist[(temp_airport) -> get_id()] + temp_distance)) {
            parents[(*it) -> get_id()] = (temp_airport) -> get_id();
            dist[(*it) -> get_id()] = (dist[(temp_airport) -> get_id()] + temp_distance);
          }
        }
      }
    }
    while (destination != source) {
      ans.push_back(destination);
      destination = parents[destination];
    }
    ans.push_back(source);
    vector<int> ans_reverse(ans.size(), 0);
    for (size_t i = 0; i < ans.size(); i++) {
      ans_reverse[ans.size()-1-i] = ans[i];
    }
    return ans_reverse;
}


bool Graph::checkvalid(Airport s, Airport d){
  if(s.valid() == false ){
    cout<<"invalid input source"<<endl;
    return false;
  }
  if(d.valid() == false){
    cout<<"invalid output source"<<endl;
    return false;
  }
  if(s.get_dd().empty()){
    cout<<"input source airport is isolated"<<endl;
    return false;
  }
  if(d.get_inc().empty()){
    cout<<"input destination is isolated"<<endl;
    return false;
  }
  return true;
}

