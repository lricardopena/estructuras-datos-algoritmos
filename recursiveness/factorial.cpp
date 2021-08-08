#include <iostream>

using namespace std;

long compute_factorial(int n){
    // base case
    if(n == 0) return 1;
    // induction
    return n * compute_factorial(n-1);
}

int main(){
    int n;
    cout << "Insert a small number: ";
    cin >> n;
    cout << compute_factorial(n) << endl;
}