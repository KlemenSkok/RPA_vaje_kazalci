#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    for(int i = 0; i < 100; i++)
        cout << rand() % 8001 - 3001 + (rand() % 100 + 1) / 100.0 << endl;

    return 0;
}

/*

interval (0, 1000] -> [1, 1001)

interval [-3000, 5000] -> [-3000, 5001)


*/