#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

struct Tocka3D {
    int x, y, z;
    char oblika[11];
};

void napolni(struct Tocka3D *ptocka) {
    ptocka->x = rand() % 99 + 1;
    ptocka->y = rand() % 79 + 1;
    ptocka->z = rand() % 54 + 1;
    strcpy(ptocka->oblika, (rand()%2) ? "krog" : "polni krog");
}

void izpis(struct Tocka3D *ptocka) {
    printf("\nX: %d\nY: %d\nZ: %d\nOblika: %s\n", ptocka->x, ptocka->y, ptocka->z, ptocka->oblika);
}

float razdalja3D(short m, short n, struct Tocka3D *ptocka) {
    float d = sqrtf(pow((ptocka+m)->x - (ptocka+n)->x, 2) + pow((ptocka+m)->y - (ptocka+n)->y, 2) + pow((ptocka+m)->z - (ptocka+n)->z, 2));
}

int main() {
    srand(time(NULL));
    struct Tocka3D tab[25], *ptocka;
    ptocka = tab;
    for(int i = 0; i < 25; i++)
        napolni(ptocka + i);

    for(int i = 1; i < 25; i += 2) {
        cout << "\nIndex: " << i;
        izpis(ptocka + i);
    }
    for(int i = 0; i < 25; i += 2) {
        cout << "\nIndex: " << i;
        izpis(ptocka + i);
    }

    system("pause");
    return 0;
}