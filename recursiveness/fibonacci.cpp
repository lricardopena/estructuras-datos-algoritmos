#include <iostream>

using namespace std;

long compute_fibonacci(int n){
    // base case
    if(n <= 2) return 1;
    // induction
    return compute_fibonacci(n-1) + compute_fibonacci(n-2);
}

int main(){
    int n;
    cout << "Insert a small number to compute the fibonacci: ";
    cin >> n;
    cout << compute_fibonacci(n) << endl;
}