#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../airport.h"
#include "../graph.h"
#include "../Helper.h"
#include "../country.h"
#include "../airport.cpp"
#include "../graph.cpp"
#include "../Helper.cpp"
#include "../country.cpp"


TEST_CASE("Test reading airports information into vector") {
	vector<Airport> airports = make_airport_list();

	// test that all the airports have been loaded into the vector
	// regardless of whether the airport is valid or invalid.
	REQUIRE(airports.size() == 14111);   
	
	// test whether the information of a specific airport is correct.
	// we test for 3391: Shanghai Hongqiao International Airport.
	REQUIRE(airports[3391].get_id() == 3391);
	REQUIRE(airports[3391].get_name() == "Shanghai Hongqiao International Airport");
	REQUIRE(airports[3391].get_IATA() == "SHA");
	REQUIRE(airports[3391].get_ICAO() == "ZSSS");
	REQUIRE(abs(airports[3391].get_lat() - 31.1979) < 0.001);
	REQUIRE(abs(airports[3391].get_lon() - 121.336) < 0.001);

	// test for valid and invalid airport nodes
	REQUIRE(airports[118].get_name() == "This airport ID does not match any existing airport in the data base");
	REQUIRE(airports[18].get_name() != "This airport ID does not match any existing airport in the data base");

}

TEST_CASE("Test case 1: reading route/edge information") {
	Graph testgraph;
	vector <Airport> airports = testgraph.get_airports();
	vector<Airport*> dd = airports[1].get_dd();
	vector<int> solutions{2, 3, 4, 5};
	for (int i = 0; i < (int) dd.size(); i++) {
		REQUIRE(count(solutions.begin(), solutions.end(), dd[i] -> get_id()));
	}
}

TEST_CASE("Test case 2: reading route/edge information") {
	Graph testgraph;
	vector <Airport> airports = testgraph.get_airports();
	vector<Airport*> dd = airports[2001].get_dd();
	vector<int> solutions{5920, 5921, 1998, 1999, 2000, 2002, 5919, 2003, 2004};
	for (int i = 0; i < (int) dd.size(); i++) {
		REQUIRE(count(solutions.begin(), solutions.end(), dd[i] -> get_id()));
	}
}

TEST_CASE("Test that the distance function works") {
	Airport p1;
	Airport p2;
	Airport p3;
	Airport p4;
	p1.set_lat(34.741100311299995);
	p1.set_lon(112.388000488);
	p2.set_lat(47.464699);
	p2.set_lon(8.54917);
	p3.set_lat(52.3466365904832);
	p3.set_lon(4.91781401731873);
	p4.set_lat(40.978101);
	p4.set_lon(-124.109);
	vector<double> solutions{8152.74445, 8536.94947};
	
	REQUIRE(abs(distance(&p1, &p2) - solutions[0]) < 0.001);
	REQUIRE(abs(distance(&p3, &p4) - solutions[1]) < 0.001);
}

TEST_CASE("Test BFS") {
	// ensures that every airport node has been traversed.
	Graph testgraph;
	vector <Airport> airports = testgraph.get_airports();
	vector<bool> visited = testgraph.BFS_all_check();
	for (int i = 1; i < (int) visited.size(); i++) {
		if (airports[i].valid()) {
			REQUIRE(visited[i]);
		} else {
			REQUIRE(!visited[i]);
		}
	}
	
}

TEST_CASE("Test shortest path") {
	Graph testgraph;
	// check shortest path within the same connected component.
	vector<int> solution1{1, 5, 3316, 3024, 994, 4059, 1020, 1031, 1036, 11229, 1033, 1032};
	vector<int> solution2{1032, 1031, 1020, 4059, 994, 3024, 3316, 5, 1};
	vector<int> real1 = testgraph.shortestPath(1, 1032);
	vector<int> real2 = testgraph.shortestPath(1032, 1);
	REQUIRE(real1 == solution1);
	REQUIRE(real2 == solution2);

	// check path across different connected components.
	vector<int> real3 = testgraph.shortestPath(69, 82);
	REQUIRE(real3.size() == 0);

}

TEST_CASE("Test betweeness centrality") {
	Graph testgraph;
	// check the bc node if the source node is within a large connected components.
	int bc_node1 = testgraph.bc_check(1);
	REQUIRE(bc_node1 == 5);

	// int bc_node2 = testgraph.bc_check();
	// sanity check if the source node is isolated
	int bc_node3 = testgraph.bc_check(89);
	REQUIRE(bc_node3 == 0);
}
