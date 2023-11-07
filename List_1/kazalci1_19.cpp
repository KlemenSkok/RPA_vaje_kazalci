#include <iostream>

using namespace std;

/*
    19. Napiši program, ki na 5. mesto prebranega niza znakov dolžine 20 vstavi prebrani niz dolžine 4. Izpiše naj novi niz.
*/

int main() {

    int n = 21;
    char niz[n], *p1 = niz;
    char niz2[5], *p2 = niz2;
    fgets(niz, n, stdin);
    fgets(niz2, 5, stdin);
    
    for(int i = 0; i < 4; i++)
        for(int j = n-1; j >= 5; j--)
            *(p1 + j) = *(p1 + j-1);
    
    for(int i = 4; i < 8; i++) {
        *(p1 + i) = *(p2 + i%4);
    }
    
    cout << niz << endl;


    return 0;
}