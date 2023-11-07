#include <iostream>

using namespace std;

/*
    16. Napiši program, ki s pomočjo kazalca prešteje, koliko samoglasnikov vsebuje prebrani niz znakov.
*/

int main() {

    char niz[20], *p = niz;
    fgets(niz, 20, stdin);

    int n = 0, i = 0;
    while(*(p + i) != '\0') {
        switch (*(p + i)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                n++;
                break;
        }
        i++;
    }
    cout << "Stevilo samoglasnikov v nizu: " << n << endl;

    return 0;
}