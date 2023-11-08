#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

struct Stanje {
    float zacetno_stanje,
    dvigPolog[100];
};

struct Racun {
    char ime[16], 
    priimek[16];
    struct Stanje stanje;
};

// a)
void napolni(struct Racun *racun) {
    char imena[3][16] = {"Janez", "Polda", "Micka"};
    char priimki[3][16] = {"Novak", "Medved", "Zajc"};

    strcpy(racun->ime, imena[rand() % 3]);
    strcpy(racun->priimek, priimki[rand() % 3]);
    racun->stanje.zacetno_stanje = (rand() %100000 + 1) / 100.0;
    for(int i = 0; i < 100; i++)
        racun->stanje.dvigPolog[i] = rand()%8001 - 3001 + (rand()%100 + 1) / 100.0;
}
// b)
void izpis(struct Racun *racun) {
    cout << racun->ime << " " << racun->priimek << endl;
    cout << "Zacetno stanje: " << racun->stanje.zacetno_stanje << endl;

    cout << "\nPOLOGI:\n";
    for(int i = 0; i < 100; i++)
        if(racun->stanje.dvigPolog[i] > 0)
            cout << racun->stanje.dvigPolog[i] << endl;
    cout << "\nDVIGI:\n";
    for(int i = 0; i < 100; i++)
        if(racun->stanje.dvigPolog[i] < 0)
            cout << racun->stanje.dvigPolog[i] << endl;

    cout << endl;
}
// c)
float stanje(struct Racun *racun) {
    float stanje = racun->stanje.zacetno_stanje;
    for(int i = 0; i < 100; i++)
        stanje += racun->stanje.dvigPolog[i];
    return stanje;
}

int main() {

    srand(time(NULL));
    struct Racun *racun = new struct Racun;

    napolni(racun);
    izpis(racun);
    cout << "Koncno stanje: " << stanje(racun) << endl;
    
    delete racun;

    return 0;
}