#include <iostream>
#include <cstring>

using namespace std;

/*
    1.	Želimo poslati mail, vendar smo imeli smolo in je poleg nas sedel lektor, ki je opazil, da nam za vejico manjka presledek. 
    Napiši program, ki bo besedilo popravil oz. dodal manjkajoče presledke za ločili. Program mora delati s kazalci! 
    Opomba: Če je več zaporednih ločil, za vsakim mora biti presledek.
    Primer:   Pozabili smo poslati prej,ker smo sli ven.In smo poslali prepozno.  
    Spremeni v: Pozabili smo poslati prej, ker smo sli ven. In smo poslali prepozno.	

*/

void vstavi_space(char *p, int mesto) {
    for(int i = strlen(p); i >= mesto; i--)
        *(p + i + 1) = *(p + i);
    *(p + mesto) = ' ';
}

int main() {

    char niz[100], *pniz = niz;
    fgets(niz, 100, stdin);

    int i = 0;
    while(i < strlen(niz)-1) {
        switch(*(pniz + i)) {
            case '.':
            case ',':
            case '!':
            case '?':
                if(*(pniz + i + 1) != ' ') {
                    vstavi_space(pniz, i+1);
                    i++;
                }
                break;
        }
        i++;
    }

    cout << pniz << endl;

    return 0;
}