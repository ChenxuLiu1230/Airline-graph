
#include "graph.h"
#include "airport.h"
#include "Helper.h"
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
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
 * @brief Used for BFS sanity check.
 * @return the vector tracking whether each of the airport node has been visited.
**/
vector<bool> Graph::BFS_all_check() {
  ofstream fout;
  fout.open("output/bfs_all_output");
  vector<bool> globalvisited(airports.size(), false); // keep track of whether each airport has been visited or not.
  for (int i = 0; i < (int) airports.size(); i++) {
    if (airports[i].valid() && !globalvisited[i]) {
      BFS_helper(i, fout, globalvisited);
    }
  }
  return globalvisited;


}

/**
 * @brief Helper function to traverse all the connected components.
 * @param : start, marks the airportID of the starting airport of the traversal.
**/
void Graph::BFS_helper(int start, ofstream & fout, vector<bool>& globalvisited) {
    queue<Airport*> container;   // used to do BFS.
    int count = 0;

    container.push(&airports[start]);
    globalvisited[start] = true; 
    while (!container.empty()) {
      Airport * curr = container.front();
      // loop through all the curr's neighbor airports, if not yet visited, push it into the queue.
      vector<Airport*> destinations = curr -> get_dd();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        if (!globalvisited[(*it) -> get_id()]) {
          container.push(*it);
          // We mark the airport as visited once the airport is pushed into the queue,
          // although it has not been truly "visited", in this way we could avoid pushing redundant airports into the queue.
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


struct Node{
	int x,y;
	Node(int index, int distance):
		x(index), y(distance) {}
};
 
struct cmp{
	bool operator()(Node a, Node b){
		if(a.y == b.y)	return a.x>b.x;
		return a.y>b.y;
	}
};

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
    priority_queue<Node, vector<Node>, cmp> p;
    p.push(Node(source, 0)); 
    while (!p.empty()) {
      Node temp_air = p.top();
      p.pop();
      int u = temp_air.x;
      visited[u] = false;
      Airport* temp_airport = &airports[u];
      vector<Airport*> destinations = temp_airport -> get_dd();
      vector<double> distance = temp_airport -> get_distance();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        int v = (*it) -> get_id();
        if (!visited[v]) {
          double temp_distance = distance[v];
          if (dist[v] > (dist[u] + temp_distance)) {
            parents[v] = u;
            dist[v] = (dist[u] + temp_distance);
            p.push(Node(v, dist[v]));
          }
        }
      }
    }
    while (destination != source) {
      if (destination == -1) {
        vector<int> ans{};
        return ans;
      }
      ans.push_back(destination);
      destination = parents[destination];
    }
    ans.push_back(source);
    reverse(ans.begin(), ans.end());
    return ans;
}


bool Graph::checkvalid(int in){
  cout<<"\n"<<endl;
  if(in<0 || in > 14111){
    cout<<"invald input airport ID"<<endl;
    return false;
  }
  Airport s = airports[in];
  if(s.valid() == false ){
    cout<<"Warning. Input: "<<in<<endl;
    cout<<s.get_name()<<"\nTry again\n"<<endl;
    return false;
  }

  else if(s.get_dd().empty() && s.get_inc().empty()){
    cout<<"\n\nThis input airport is isolated"<<endl;
  }

  return true;
}

vector<Airport> Graph::get_airports(){return airports;}


/**
 * @brief Helper function that calculates shortest paths used for betweenness centrality.
 * @param : source, the airportID of the source airport.
 * @return shortest path from the source airport to all the other airports in the graph.
**/ 
vector<int> Graph::Dijkastra(int source){
    vector<bool> visited(airports.size(), false); // keep track of whether each airport has been visited or not.
    vector<int> parents(airports.size(), -1); // keep track of each airport's parent node.
    vector<int> dist(airports.size(), INT32_MAX); // keep track of the minimum distance from source to this one.
    vector<int> ans{};

    dist[source] = 0;
    priority_queue<Node, vector<Node>, cmp> p;
    p.push(Node(source, 0)); 
    while (!p.empty()) {
      Node temp_air = p.top();
      p.pop();
      int u = temp_air.x;
      visited[u] = false;
      Airport* temp_airport = &airports[u];
      vector<Airport*> destinations = temp_airport -> get_dd();
      vector<double> distance = temp_airport -> get_distance();
      for (auto it = destinations.begin(); it != destinations.end(); ++it) {
        int v = (*it) -> get_id();
        if (!visited[v]) {
          double temp_distance = distance[v];
          if (dist[v] > (dist[u] + temp_distance)) {
            parents[v] = u;
            dist[v] = (dist[u] + temp_distance);
            p.push(Node(v, dist[v]));
          }
        }
      }
    }
    return parents;
}


/**
 * @brief Find the airport with the largest betweenness centrality with respect to a source node.
 * @param : source, the airportID of the source airport.
 * @return print out relevant information of the most "important" stop with the largest betweenness centrality.
**/ 
void Graph::bc(int source){
  Airport s = airports[source];
  if(s.get_dd().empty() && s.get_inc().empty()){
    cout<<"\nBecause "<<source<<" is isolated, it is meaningless for the system to find betweeness centrality airport node\n"<<endl;
    return;
  }
  //initialize variables
  vector<int> count(14111,0);
  vector<int> parents = Dijkastra(source);
  vector<int> ans;
  int total_paths = 0;
  size_t source1 = (size_t)source;

  //find all shortest paths, from input source to the rest of airports
  for(size_t i = 1; i<14111; i++){
    if(i == source1) continue;                  //if i is source, skip it
    if(airports[i].valid() == false) continue;  //if airport i is invalid, skip it
    int destination = (int)i;                     //temp value that stores the current destination of the path
    while (destination != source) {            //get the short path from source to current destination
      if (destination == -1) {
        vector<int> a{};
        ans = a;
        break;
      }
      ans.push_back(destination);
      destination = parents[destination];
    }
    for(size_t j = 0; j<ans.size(); j++){       //for any airports in the path, increment once in "count"
      int temp1 = ans[j];                        //ID of the airport in the path
      if(temp1 == (int)i) continue;              //skip current destination
      else count[temp1]++;                     
    }
    if(!ans.empty()) total_paths++;   //keep track of total number of paths
    ans.clear();
  }
  int out;
  int temp2 =0;
  for(size_t i = 0; i<count.size(); i++){
    if(temp2<count[i]){
      temp2 = count[i];
      out = i;
    }
  }
  cout<<"\nWhen the source airport is "<<airports[source].get_name()<<", ID "<<source<<"."<<endl;
  if(airports[out].valid() == true){
    cout<<"The airport node with the largest  betweeness centrality is: "<<airports[out].get_name()<<", ID "<<out<<"."<<endl;
    cout<<"The betweeness centrality value is: "<<temp2<<"/"<<total_paths<<"\n\n"<<endl;
  }else{
    cout<<"There is no intermediate airport among all the routes!\n\n"<<endl;
  }

}

/**
 * @brief Test function for bc
 * @param : source, the airportID of the source airport.
 * @return the airport node with the largest bc wpt to the source node.
**/ 
int Graph::bc_check(int source){
  Airport s = airports[source];
  if(s.get_dd().empty() && s.get_inc().empty()){
    
    return 0;
  }
  //initialize variables
  vector<int> count(14111,0);
  vector<int> parents = Dijkastra(source);
  vector<int> ans;
  int total_paths = 0;
  size_t source1 = (size_t)source;

  //find all shortest paths, from input source to the rest of airports
  for(size_t i = 1; i<14111; i++){
    if(i == source1) continue;                  //if i is source, skip it
    if(airports[i].valid() == false) continue;  //if airport i is invalid, skip it
    total_paths++;                              //keep track of total numbers of paths
    int destination = (int)i;                     //temp value that stores the current destination of the path
    while (destination != source) {            //get the short path from source to current destination
      if (destination == -1) {
        vector<int> a{};
        ans = a;
        break;
      }
      ans.push_back(destination);
      destination = parents[destination];
    }
    for(size_t j = 0; j<ans.size(); j++){       //for any airports in the path, increment once in "count"
      int temp1 = ans[j];                        //ID of the airport in the path
      if(temp1 == (int)i) continue;              //skip current destination
      else count[temp1]++;                     
    }
    ans.clear();
  }
  int out;
  int temp2 =0;
  for(size_t i = 0; i<count.size(); i++){
    if(temp2<count[i]){
      temp2 = count[i];
      out = i;
    }
  }
  return out;

}

 