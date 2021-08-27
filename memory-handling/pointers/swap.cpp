#include <iostream>

using namespace std;

void swap_variables(int *px, int *py){
    int tmp = *px; // Asign the value of px to temp variable

    *px = *py; // The value of *px will be the the value of *py
    *py = tmp; // The value of *py will be tmp 
}


void add_10(int *px){
    *px += 10;
}


int main(){
    int x = 1, y = -2;

    cout << "Value of x: " << x << endl << "Value of y: " << y << endl;
    swap_variables(&x, &y);
    cout << "New value of x: " << x << endl << "New value of y: " << y << endl;

    return 0;
}