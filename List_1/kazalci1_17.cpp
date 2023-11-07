#include <iostream>

using namespace std;

/*
    17. Napiši program, ki v prebrani niz znakov dolžine 20 vstavi znak a na 10. mesto in izpiše novi niz
    (uporabi kazalce).
*/

int main() {

    int n = 20, mesto = 10;
    char niz[n], *p = niz;
    fgets(niz, n, stdin);

    for(int i = n-2; i >= mesto; i--) {
        *(p + i) = *(p + i-1);
    }

    *(p + mesto-1) = 'a';
    cout << niz << endl;

    return 0;
}