#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> bubble_sort_algorithm(vector<int> A){
    // Get the size of the vector
    int n = A.size();

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n - i -1 ; j++){
            if (A[j] > A[j + 1]){
                // Exchange A[j + 1] and A[j]
                int tmp_value = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp_value;
            }
        }
    }
    return A;
}

int main(){
    int num_items = 10;
    vector<int> x(num_items, 0);
    
    // use srand() for different outputs
    srand(time(0));
  
    // Generate value using generate function
    generate(x.begin(), x.end(), []() {
        return rand() % 100;
    });
    
    cout << "Vector before sorting " << endl;
    // Print the values in the vector
    for (int i = 0; i < num_items; i++) {
        cout << x[i] << " ";
    }

    vector<int> x_order = bubble_sort_algorithm(x);

    cout << endl << "Vector afert sorting " << endl;
    // Print the values in the vector
    for (int i = 0; i < num_items; i++) {
        cout << x_order[i] << " ";
    }
    cout << endl;

    return 0;
}