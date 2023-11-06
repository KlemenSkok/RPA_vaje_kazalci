#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

void izpisFtab(float *px, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(px + i) << " ";
    }
    cout << endl;
}

// 3. naloga
void reverse(char niz[]) {
    char *pniz = niz;
    for(int i = 0; i < strlen(niz)/2; i++) {
        char tmp = *(pniz + i);
        *(pniz + i) = *(pniz + strlen(niz)-i-1);
        *(pniz + strlen(niz)-i-1) = tmp;
    }
}
// 4. naloga
void napolni(float x[], int n) {
    float *px = x;
    for(int i = 0; i < n; i++) {
        *(px + i) = (float)(rand() % 11099 - 5099) / 100.0;
        //cout << *(px + i) << " ";
    }
    //cout << endl;
}

// 5. naloga - boljša
void zamakniLevo(float tab[], int n, int koliko) {
    float *ptab = tab;
    for(int i = 0; i < koliko; i++) {
        float tmp = *ptab;
        for(int j = 0; j < n-1; j++)
            *(ptab + j) = *(ptab + j+1);
        *(ptab + n-1) = tmp;
    }
}

// 5. naloga - brez dvojne zanke
void zamakniLevoV2(float tab[], int n, int koliko) {
    float *ptab = tab;
    float tmp[koliko];
    for(int i = 0; i < koliko; i++)
        tmp[i] = *(ptab + i);

    for(int i = 0; i < n-koliko; i++)
        *(ptab + i) = *(ptab + i + koliko);
    for(int i = 0; i < koliko; i++) 
        *(ptab + n-koliko+i) = tmp[i];
}

int main() {
    srand(time(NULL));
    // naloga 3
    /* char niz[16];
    cout << "Naloga 3: vnesi niz, da ga obrnem: \n";
    fgets(niz, 16, stdin);
    reverse(niz);
    cout << niz << endl; */

    // naloga 4,5
    int n = rand() % 100 + 1;
    float tab[n];
    napolni(tab, n);
    cout << "Naloga 4: \n\n";
    izpisFtab(tab, n);

    zamakniLevo(tab, n, 5);
    cout << "\nZamaknjeno (naloga 5): \n\n";
    izpisFtab(tab, n);

    system("pause");
    return 0;
}

/*

1, 2, 3, 4, 5, 6, 7
-
2, 3, 4, 5, 6, 7, 1
-
3, 4, 5, 6, 7, 1, 2

*/