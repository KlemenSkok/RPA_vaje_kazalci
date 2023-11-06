#include <iostream>

using namespace std;

/*
    12. Napiši program, ki prebere 2 realni števili in ju sešteje s pomočjo kazalcev.
    13. Napiši program, ki izpiše manjšega izmed dveh števil (primerjanje izvedi s pomočjo kazalcev).
*/

int main() {

    float st1, st2, *p1, *p2;
    p1 = &st1;
    p2 = &st2;
//naloga 12
    cin >> *p1;
    cin >> *p2;
    cout << "Vsota: " << *p1 + *p2 << endl;
// naloga 13
    cout << "Manjse stevilo je " << ((*p1 < *p2) ? *p1 : *p2) << endl;

    return 0;
}