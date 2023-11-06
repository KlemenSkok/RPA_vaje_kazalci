#include <iostream>
#include <string.h>

using namespace std;

int main() {

    char beseda[22], *pniz = beseda;
    fgets(beseda, 20, stdin);
    int n;
    do {
        cin >> n;
    } while(n < 1 || n > 20);
    char znak;
    cin >> znak;

    for(int i = strlen(beseda); i >= n-1; i--)
        *(pniz+i+1) = *(pniz + i);
    *(pniz + n-1) = znak;
    cout << beseda << endl;

    system("pause");
    return 0;
}