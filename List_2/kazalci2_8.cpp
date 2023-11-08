#include <iostream>
#include <cstring>

using namespace std;
// a)
struct Graficna {
    bool je_vgrajena;
    char znamka[10],
    model[10];
    int pomnilnik; // v GB
};

struct Disk {
    char proizvajalec[20],
    vrsta_diska[10];
    int kapaciteta; // v GB
};

struct Racunalnik {
    char vrstaCPU[20];
    float taktCPU; //GHz
    struct Graficna gpu;
    struct Disk diski[16];
};

int getKapaciteta(struct Racunalnik x) {
    int sum = 0;
    for(int i = 0; i < 16; i++) {
        if(x.diski[i].kapaciteta > 0)
            sum += x.diski[i].kapaciteta;
    } 
    return sum;
}
// b)
void izpisDiske(struct Racunalnik *ptr) {
    for(int i = 0; i < 100; i++) {
        if(!strcmp(ptr->vrstaCPU, "I7"))
            cout << "Skupna kapaciteta diskov v R" << i << ": " << getKapaciteta(*(ptr + i)) << "GB\n";
    }
}
// c)
void razvrsti(struct Racunalnik *ptr) {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100-i-1; j++) {
            if(strcmp((ptr+j)->vrstaCPU, (ptr+j+1)->vrstaCPU) == -1) {
                struct Racunalnik *tmp = new struct Racunalnik;
                *tmp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = *tmp;
            }
            else if(strcmp((ptr+j)->vrstaCPU, (ptr+j+1)->vrstaCPU) == 0) {
                if(strcmp((ptr+j)->gpu.model, (ptr+j+1)->gpu.model) == -1) {
                    struct Racunalnik *tmp = new struct Racunalnik;
                    *tmp = *(ptr+j);
                    *(ptr+j) = *(ptr+j+1);
                    *(ptr+j+1) = *tmp;
                }
            }
        }
    }
}

void izpis_vse(struct Racunalnik *ptr) {
    for(int i = 0; i < 100; i++) {
        cout << "Racunalnik " << i << ":\n";
        cout << "Procesor: " << ptr->vrstaCPU << ", " << ptr->taktCPU << endl;

        if(ptr->gpu.je_vgrajena)
            cout << "GPU: " << ptr->gpu.znamka << " " << ptr->gpu.model << ", " << ptr->gpu.pomnilnik << "GB\n";
        
        cout << "Diski: \n";
        for(int i = 0; i < 16; i++) {
            if(ptr->diski[i].kapaciteta > 0)
                cout << ptr->diski[i].vrsta_diska << ", " << ptr->diski[i].proizvajalec << ", " << ptr->diski[i].kapaciteta << " GB\n";
        }
    }
}

int main() {

    struct Racunalnik tab[100], *ptr = tab;
    izpisDiske(ptr);
    razvrsti(ptr);
    izpis_vse(ptr);

    return 0;
}