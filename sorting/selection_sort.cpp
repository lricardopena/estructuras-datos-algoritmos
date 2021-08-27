#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int global_i = 0; 

vector<int> selection_sort_algorithm(vector<int> A){
    // Get the size of the vector
    int n = A.size();

    for(int i = 0; i < n - 1 ; i++){
        int min_idx = i;
        for(int j = i + 1; j < n ; j++){
            global_i++;
            if (A[j] < A[min_idx]){
                // Exchange A[j] and A[min_idx]
                int tmp_value = A[j];
                A[j] = A[min_idx];
                A[min_idx] = tmp_value;
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

    vector<int> x_order = selection_sort_algorithm(x);

    cout << endl << "Vector afert sorting " << endl;
    // Print the values in the vector
    for (int i = 0; i < num_items; i++) {
        cout << x_order[i] << " ";
    }
    cout << endl << global_i << endl;

    return 0;
}