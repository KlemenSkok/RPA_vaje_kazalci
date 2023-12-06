#include <iostream>
#include <cstring>

using namespace std;

/*
    1.	Pisali smo mail in potem smo opazili, da se nam zatikajo nekatere tipke. 
    Odločili smo se, da bomo napisali program, ki bo za nas preverjal in popravljal to napako – odstranil bo ponavljanja tipk. 
    Program mora biti realiziran s kazalci in enim nizom.
    
    Primer: Moj mail je ze skoraj napisan…. Opppazila sem,,,,,,,, da se zatikajo tipke...
    popravljeno: Moj mail je ze skoraj napisan. Opazila sem, da se zatikajo tipke.  

*/

void del_znak(char *p, int mesto) {
    for(int i = mesto; i < strlen(p); i++) {
        *(p + i) = *(p + i + 1);
    }
}

int main() {

    char niz[100], *pniz = niz;
    fgets(niz, 100, stdin);

    int i = 0;
    while(i < strlen(niz) - 1) {
        if(*(pniz + i) == *(pniz + i + 1))
            del_znak(pniz, i);
        else i++;
    }

    cout << pniz << endl;


    return 0;
}