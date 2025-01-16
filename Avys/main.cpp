#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Avis {
    char vardas[11];
    char DNR[21];
    int koeficientas;
};

void skaitytiDuomenis(Avis avys[], int &n, int &m, int &tiriamosIndex) {
    ifstream fin("U2.txt");
    fin >> n >> m;
    int tiriamosNr;
    fin >> tiriamosNr;
    tiriamosIndex = tiriamosNr - 1;
    for (int i = 0; i < n; i++) {
        fin >> avys[i].vardas >> avys[i].DNR;
        avys[i].koeficientas = 0;
    }
    fin.close();
}

int skaiciuotiKoeficienta(const char DNR1[], const char DNR2[], int m) {
    int koef = 0;
    for (int i = 0; i < m; i++) {
        if (DNR1[i] == DNR2[i]) {
            koef++;
        }
    }
    return koef;
}

void rikiuoti(Avis avys[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (avys[i].koeficientas < avys[j].koeficientas ||
                (avys[i].koeficientas == avys[j].koeficientas &&
                 strcmp(avys[i].vardas, avys[j].vardas) > 0)) {
                Avis temp = avys[i];
                avys[i] = avys[j];
                avys[j] = temp;
            }
        }
    }
}

int main() {
    Avis avys[20];
    int n, m, tiriamosIndex;
    skaitytiDuomenis(avys, n, m, tiriamosIndex);
    for (int i = 0; i < n; i++) {
        if (i != tiriamosIndex) {
            avys[i].koeficientas = skaiciuotiKoeficienta(avys[tiriamosIndex].DNR, avys[i].DNR, m);
        }
    }
    ofstream fout("U2rez.txt");
    fout << avys[tiriamosIndex].vardas << endl;

    for (int i = tiriamosIndex; i <= n; i++) {
        avys[i] = avys[i + 1];
    }
    n--;
    rikiuoti(avys, n);


    for (int i = 0; i < n; i++) {
        fout << avys[i].vardas << " " << avys[i].koeficientas << endl;
    }
    fout.close();

    return 0;
}
