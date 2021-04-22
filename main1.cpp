#include <iostream>
#include <string>
using namespace std;

void test1(int x, int y){
    cout << "This is test 1!" << endl;
}

void test2(int x) {
    cout << "This is test 2!" << endl;
}

void test3(int x, int y) {
    cout << "This is test 3!" << endl;
}

void test4() {
    cout << "This is test 4!" << endl;
}


int main(){
	bool check1 = true;
    while(check1) {
        cout << "Welcome to our program! Please input 1, 2, 3 or 4 to choose test type and start" << endl;
        cout << "If you want to quit our program, press 9!" << endl;

        int test_type;
        cin >> test_type;
        switch (test_type) {
            case 1: {
            	cout << "Tip: you have successful entered Test1" << endl;

            	bool check = true;
            	while(check){
            		cout << "Please input two parameters([0-14111]): " << endl;
                	int x, y;
                	cin >> x >> y;
                	// TODO: Please check the value of x and y before using test1!
                	test1(x, y);
            		int d_check;
            		cout << "Press 1 to quit test1, press other to continue..." << endl;
            		cin >> d_check;
            		if(d_check == 1){
            			check = false;
            		}
            	}
            	break;
            }
            case 2: {
            	cout << "Tip: you have successful entered Test2" << endl;

            	bool check = true;
            	while(check){
            		cout << "Please input one parameter ([0-14111]): " << endl;
                	int x;
                	cin >> x;
                	// TODO: Please check the value of x before using test2!
                	test2(x);

            		int d_check;
            		cout << "Press 2 to quit test2, press other to continue..." << endl;
            		cin >> d_check;
            		if(d_check == 2){
            			check = false;
            		}
            	}
            	break;
                
            }
            case 3: {
            	cout << "Tip: you have successful entered Test3" << endl;

            	bool check = true;
            	while(check){
            		cout << "Please input two parameters([0-14111]): " << endl;
                	int x, y;
                	cin >> x >> y;
                	// TODO: Please check the value of x and y before using test3!
                	test1(x, y);
            		int d_check;
            		cout << "Press 3 to quit test3, press other to continue..." << endl;
            		cin >> d_check;
            		if(d_check == 3){
            			check = false;
            		}
            	}
            	break;
            }
            case 4:{
            	cout << "Tip: you have successful entered Test4" << endl;

            	bool check = true;
            	while(check){
                	test4();
            		int d_check;
            		cout << "Press 4 to quit test4, press other to continue..." << endl;
            		cin >> d_check;
            		if(d_check == 4){
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