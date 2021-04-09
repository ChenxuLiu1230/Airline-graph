# CS 225 Data Structures
## Project Proposal (jibingy2-bojia2-chenxul2-sw18)

1. **Leading Question**
Given any two cities, we would like to find the shortest path between them with the shortest distance along the route totally. Then, we would like to display this route on an interactive map of the globe, or find the airport ID node with the largest betweenness centrality, which means this airport has more control or influence on the global flight routes.

2. **Dataset Acquistion and Processing**
We propose using the [OpenFlights Dataset](https://openflights.org/data.html). We will mainly use three subsets of this data, airports, routes and countries. These datasets provide information about the source airport, destination airport, airline, the cities airports located in, and the exact location of the airport represented by longtitude and latitude. Since the data is provided in `*.dat` format, we will cite the reference from [Stack Overflow](https://stackoverflow.com/questions/15528468/how-to-read-dat-files-in-c) or from the `readFromFile.cpp` provided by the course staff to load data into the array format. To be specific about our graph structure, we propose that each airport (or airport ID) will be a node in the graph, and an edge exists between 2 nodes if there exists a flight or route between the 2 airports. In addition, the weights of the edges will be measured by the distance between the source and the destination airports, computed based on the information of the longtitude and latitude of the airports. Finally, the dataset is from the real world and may have some flawed data. To handle this kind of drawback, we will simply give up any data that involves incomplete or incorrect information.

3. **Graph Algorithms**
For the graph traversal, we propose to implement a simple BFS and may print the basic information of the airports, including city and country during the process of traversal.
For the first algorithm, we propose implementing Dijikstra's Algorithm (or maybe A* search or other variants) to find the shortest path between two cities or airports. We expect the input to be the starting airport ID node and the destination
airport ID node, and the output to be the corresponding shortest path in terms of the shortest distance from the source to the destination airports.
For the second algorithm, we are going to implement Betweenness centrality (or create a graphical output of the path on the map, to be determined). It will take two countries as inputs and output the most essential third country airport at which aircrafts stopover frequently.

4. **Timeline**
Week 1
April 7 	- sync to complete project proposal and team contract
April 9	 	- submit project proposal and team contract
April 10 	- set up initial repository and Makefile, make class for the project, make sure data files can be sucessfully read and stored

	Week 2
April 11-12 - finish reading in data into vector or array format and write simple tests to verify correctness
April 13-16 - convert array format into graph format and pass simple tests
April 17 	- start working on writing algorithm: BFS, shortest path, etc
 
	Week 3
April 18-23 - continue working on writing algorithm: BFS, shortest path, etc
April 24	- continue working on functions if not finished.

	Week 4
April 25-30 - debuging and testing effectiveness

	Week 5
May 2-8		- find "essential" airport based on betweenness centrality or write graph projection onto World Map and verify with tests
         - finish report, presentation vedio
