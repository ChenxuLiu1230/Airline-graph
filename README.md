# Final Project for CS 225


## Team Members:  

Jibing Yao (jibingy2), Bo Jia (bojia2), Chenxu Liu (chenxul2), Shuchen Wu (sw18)

<!-- jibingy2-bojia2-chenxul2-sw18 -->


## How to build and run our system?

1. Compile and run our main.cpp file, on **Linux (EWS) terminal**, type:

   ```C++
   $ make
   
   $ ./finalproj
   ```
  
2. You will see a message indicating a successful entry
3. Follow the prompts to select the test type and start the test
4. Enter parameter information input as prompted
5. After the test is over, you can choose to repeat the test or exit the current test

- *Note:* When two parameters are needed, please separate them with a space.
- *Note:* All of our algorithms are implemented in graph.cpp, while the functions that are used to read data are implemented in helper.cpp


## Project Description:

In this project, we successfully implemented the following 3 algorighms:
- We use the **BFS algorithm** to traverse all of the airport nodes in the graph we created.
- we use the **Dijkastra algorithm** to generate the shortest path between input source airport and destination airport.
- We use the **Betweenness Centrality algorithm** to find the airport ID node with the largest betweenness centrality.