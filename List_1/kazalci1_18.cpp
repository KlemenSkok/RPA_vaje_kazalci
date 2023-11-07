#include <iostream>

using namespace std;

/*
    17. Napiši program, ki iz prebranega niza znakov dolžine 25 izbriše 5,6 in 7. znak ter izpiše novi niz.
*/

int main() {

    int n = 25;
    char niz[n], *p = niz;
    fgets(niz, n, stdin);
    int mesto = 5;

    for(int i = mesto-1; i < n-3; i++)
        *(p + i) = *(p + i+3);
    cout << niz << endl;

    return 0;
}