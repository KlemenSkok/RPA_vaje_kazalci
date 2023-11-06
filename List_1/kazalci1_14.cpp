#include <iostream>

using namespace std;

/*
    14. Napiši program, ki s pomočjo kazalcev izpiše tabelo celih števil v obratnem vrstnem redu 
    (od zadnjega elementa proti prvemu).
*/

int main() {

    int n = 10;
    int tab[n] = {1,2,3,4,5,6,7,8,9,10};
    int *p = tab;

    for(int i = n-1; i >= 0; i--)
        cout << *(p + i) << " ";
    cout << endl;

    return 0;
}