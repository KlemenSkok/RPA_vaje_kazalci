# Vaje s kazalci

```cpp
#include <iostream>
using namespace std;
int main()
{
    char c = 'w';
    char *k1, **k2, ***k3, ****k4;
    k1 = &c;
    k2 = &k1;
    k3 = &k2;
    k4 = &k3;
    cout << ****k4 << endl;
    cout << ***k4 << endl;
    return 0;
}
```

Ta program najprej izpiše vrednost spremenljivke c (`****k4`), nato pa še naslov te spremenljivke (`***k4`). ker gre za tip `char`, bo vseeno izpisalo vrendost spremenljivke (`w`).

#

```cpp
#include <iostream>
using namespace std;
int main()
{
    char niz[] = "aaabbbcdef";
    cout << niz + 5;
}
```
Tudi `niz` je kazalec, zato mu lahko prištevamo vrednost. Funkcija izpiše od seštevka naprej.

#
