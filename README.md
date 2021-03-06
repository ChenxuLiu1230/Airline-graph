# Final Project for CS 225


## Team Members:  

Jibing Yao (jibingy2), Bo Jia (bojia2), Chenxu Liu (chenxul2), Shuchen Wu (sw18)

<!-- jibingy2-bojia2-chenxul2-sw18 -->


## How to find documents?

1. ***Contract*** and ***Proposal*** can be found in repository [Contract&Proposal](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/Contract%26Proposal).
2. ***Development log*** can be found in repository [Development Log](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/Development%20Log)
3. ***Final report*** can be found in repository [Final project report](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/Final%20Project%20report)
4. ***Presentation PPT and video*** can be found in repository [Final Project Presentation](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/Final%20Project%20Presentation). To view our presentation video, please download the video and watch :)
5. ***Data set*** can be found in repository [data](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/data).
6. ***outputs of BFS functions*** can be found in repository [output](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/output).


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
6. Test cases of our project is located in [tests](https://github-dev.cs.illinois.edu/cs225-sp21/jibingy2-bojia2-chenxul2-sw18/tree/master/tests). To run our test, type:
   ```C++
   $ make test
   
   $ ./test
   ```
 
   After running the test cases, you should see the following output in the terminal:

   ![Test Cases](tests/test.png)
- *Note: When two parameters are needed, please separate them with a **space** or you can press **enter** to after your first input parameter.*
- *Note: All of our algorithms are implemented in graph.cpp, while the functions that are used to read data are implemented in helper.cpp.*


## Project Description:

In this project, we successfully implemented the following 3 algorithms:
- We use the **BFS algorithm** to traverse all of the airport nodes in the graph we created.
- We use the **Dijkastra algorithm** to generate the shortest path between input source airport and destination airport.
- We use the **Betweenness Centrality algorithm** to find the airport node with the largest betweenness centrality.
