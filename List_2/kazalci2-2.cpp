#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char ime[21], priimek[34], *pime = ime, *ppri = priimek;
    fgets(ime, 20, stdin);
    fgets(priimek, 30, stdin);

    for(int i = strlen(priimek); i >= 0; i--)
        *(ppri+i+3) = *(ppri + i);
    *(ppri) = *(pime);
    *(ppri + 1) = '.';
    *(ppri + 2) = ' ';

    cout << priimek << endl;
    
    system("pause");
    return 0;
}