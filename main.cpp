
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <sys/resource.h>
#include "readFromFile.hpp"
#include "country.h"
#include "airport.h"
#include "graph.h"
#include "Helper.cpp" 
using namespace std;

//User interface is constructed below
int main()
{	
	cout<<"\n\n\n\n"<<"Initializing..."<<endl;
	increase_stack_size();
	// // test travese the airports array
	// vector <Airport> airport_list = make_airport_list();	
	// int start;
    // for (int i = 0; i < (int) airport_list.size(); i++) {
    //   if (airport_list[i].get_name() == "Melitopol Air Base") {
    //     start = i;
    //   }
    // }
	// cout << start << endl;
	// test BFS

	Graph testgraph;
	vector <Airport> airport_list = testgraph.get_airports();
	// testgraph.BFS_all();
	// testgraph.BFS_all();
	// testgraph.BFS_id(118);
	// testgraph.BFS_id(1998);

	cout<<"\n\n"<<endl;

	bool check1 = true;
	cout << "Welcome to our program!"<<endl;
		cout<<"Enter 1 to search for aiport's information."<<endl;
		cout<<"Enter 2 to check out destinations of your input airport."<<endl;
		cout<<"Enter 3 to find shortest route between your input source airport and destination airport."<<endl;
		cout<<"Enter 4 to perform Betweeness Centraity with respect to your input airport as source"<<endl;
    while(check1) {
        cout<<"\n\n";
		cout<<"Please input 1, 2, 3 or 4 to choose test type and start" << endl;
        cout << "If you want to quit our program, press 9!" << endl;

        int test_type;
        cin >> test_type;
        switch (test_type) {
            case 1: {
            	cout << "Tip: you have successfully entered Test1" << endl;
            	bool check = true;
            	while(check){
            		cout << "Please input one parameter([0-14111]): " << endl;
                	int x;
                	cin >> x;
					cout<<"\nInput values are successfully read."<<"\nPlease wait for system to operate."<<endl;
                	if(testgraph.checkvalid(x) == false) continue;
					// TODO: Please check the value of x and y before using test1!
                	test_airport_list(airport_list,x);
            		int d_check;
            		cout << "Press 1 to search for other airports , press other integers to quit..." << endl;
            		cin >> d_check;
            		if(d_check != 1){
            			check = false;
            		}
            	}
            	break;
            }
            case 2: {
            	cout << "Tip: you have successfully entered Test2" << endl;
            	bool check = true;
            	while(check){
            		cout << "Please input one parameter ([0-14111]): " << endl;
                	int x;
                	cin >> x;
					cout<<"\nInput value is successfully read."<<"\nPlease wait for system to operate."<<endl;
                	if(testgraph.checkvalid(x) == false) continue;
					// TODO: Please check the value of x before using test2!                	
					test_read_routes(airport_list,x);
            		int d_check;
            		cout << "Press 2 to search for another airport's destination(s), press other integers to quit..." << endl;
            		cin >> d_check;
            		if(d_check != 2){
            			check = false;
            		}
            	}
            	break;                
            }
            case 3: {
            	cout << "Tip: you have successfully entered Test3" << endl;
            	bool check = true;
            	while(check){
            		cout << "Please input two parameters([0-14111]): " << endl;
                	int x, y;
                	cin >> x >> y;
					cout<<"\nInput values are successfully read."<<"\nPlease wait for system to operate.";
                	if(testgraph.checkvalid(x) == false) continue;
					if(testgraph.checkvalid(y) == false) continue;
					// TODO: Please check the value of x and y before using test3!
					vector <int> path = testgraph.shortestPath(x,y);
					if(path.size() != 0){
						cout<<"The shortest path is: \n\n";
						for(size_t i = 0; i<path.size(); i++){
							int temp = path[i];
							if(i == 0) cout<<airport_list[temp].get_name();
							else cout<<"->" <<airport_list[temp].get_name();
						}
						cout<<"\n\n";
						for(size_t i = 0; i<path.size(); i++){
							int temp = path[i];
						if(i == 0) cout<<temp;
						else cout<<"->" <<temp;
						}
					}else{
						cout<<"\n";
						cout<<"Cannot find routes"<<endl;
					}
					for(int i = 0; i<5; ++i){
						cout<<endl;
					}
            		int d_check;
            		cout << "Press 3 to search for another route, press other integers to quit..." << endl;
            		cin >> d_check;
            		if(d_check != 3){
            			check = false;
            		}
            	}
            	break;
            }
            case 4:{
            	cout << "Tip: you have successfully entered Test4" << endl;

            	bool check = true;
            	while(check){
                	cout << "Please input one parameters([0-14111]): " << endl;
                	int x;
                	cin >> x;
					cout<<"\nInput values are successfully read."<<"\nPlease wait for system to operate."<<endl;
                	if(testgraph.checkvalid(x) == false) continue;
					// TODO: Please check the value of x and y before using test1!
                	testgraph.bc(x);
            		int d_check;
            		cout << "Press 4 to try test another airport, press other integers to quit..." << endl;
            		cin >> d_check;
            		if(d_check != 4){
            			check = false;
            		}
            	}
            	break;
            }
            case 9:{
            	check1 = false;
            	break;
            }
            default:{
                cout << "Invalid input format, Please try again!" << endl;
            }
        }
    }

	return 0;
}



