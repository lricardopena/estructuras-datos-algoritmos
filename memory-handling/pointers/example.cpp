#include <iostream>

using namespace std;

int main(){
    int x = 1;
    int *ip; /* ip is a pointer to an int */
    ip = &x; /* ip now points to x */
    cout << "Memory address of x: " << ip << endl 
    << "Value of x: " << *ip << endl;

    *ip = 0; /* the value of x now is 0 */

    cout << "New memory address of x: " << ip << endl 
    << "New value of x: " << x << endl;


    
    for(int i = 0 ; i < 10 ; i++){
        int j = 1 + (++i);
        cout << j << ",";
    }

    cout << endl;


    for(int i = 0 ; i < 10 ; ++i){
        int j = 1 + (i++);
        cout << j << ",";
    }
    cout << endl;


}