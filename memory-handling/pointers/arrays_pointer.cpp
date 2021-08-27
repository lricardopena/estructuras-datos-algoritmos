#include <iostream>

using namespace std;

int main(){
    int a[10], *pa;

    for(int i = 0; i < 10 ; i++){
        a[i] = (i + 1) * 100;
    }

    pa = &a[0];

    cout << *pa << endl;

    pa += 3;

    cout << *pa << endl;


    pa -= 2;

    cout << *pa << endl;


    char greeting[] = "Hello Mundo12!";

    for(char *s2 = &greeting[0]; *s2 != '\0' ; s2++){
        cout << *s2;
    }
    
    cout << endl;


}