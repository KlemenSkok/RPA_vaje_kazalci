#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

struct Stanje {
    float zacetno_stanje;
    float dvigPolog[100];
};

struct Racun {
    char ime[16], priimek[16];
    struct Stanje stanje;
};

void napolni(struct Racun *ptr) {
    const char names[][10] = {"Janez", "Polda", "Micka"};
    const char surnames[][10] = {"Novak", "Medved", "Zajc"};

    strcpy(ptr->ime, names[rand() % 3]);
    strcpy(ptr->priimek, surnames[rand() % 3]);
    ptr->stanje.zacetno_stanje = (float)(rand()%1000 + 1);
    for(int i = 0; i < 100; i++)
        ptr->stanje.dvigPolog[i] = (float)(rand()%8001 - 3000);
}

void izpis(struct Racun *ptr) {
    printf("Lastnik racuna: %s %s\n", ptr->ime, ptr->priimek);
    printf("Zacetno stanje: %f\n\n", ptr->stanje.zacetno_stanje);
    cout << "Pologi: \n";
    for(int i = 0; i < 100; i++)
        if(ptr->stanje.dvigPolog[i] >= 0.0)
            cout << ptr->stanje.dvigPolog[i] << endl;
    cout << "\n-----------------------------------\nDvigi: \n";
    for(int i = 0; i < 100; i++)
        if(ptr->stanje.dvigPolog[i] < 0.0)
            cout << ptr->stanje.dvigPolog[i] << endl;
}

float stanje(struct Racun racun) {
    struct Racun *ptr = &racun;
    float *ptab = ptr->stanje.dvigPolog;
    float stanje = ptr->stanje.zacetno_stanje;
    for(int i = 0; i < 100; i++)
        stanje += *(ptab + i);
    return stanje;
}

int main() {

    srand(time(NULL));
    struct Racun racun, *ptr;
    ptr = &racun;

    napolni(ptr);
    izpis(ptr);
    cout << "------------------------------\n\nTrenutno stanje: " << stanje(racun) << endl;


    //system("pause");
    return 0;
}