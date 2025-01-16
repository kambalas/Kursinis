#include <iostream>
#include <fstream>

using namespace std;

const int MAX_N = 50;
int nGilija, nEglija;
int gilijaNominalai[MAX_N], eglijaNominalai[MAX_N];
int gilijaMonetos[MAX_N], eglijaMonetos[MAX_N];

void skaitytiDuomenis() {
    ifstream fin("U1.txt");
    fin >> nGilija;
    for (int i = 0; i <= nGilija; i++)
        fin >> gilijaNominalai[i];
    for (int i = 0; i < nGilija; i++)
        fin >> gilijaMonetos[i];
    fin >> nEglija;
    for (int i = 0; i < nEglija; i++)
        fin >> eglijaNominalai[i];
    for (int i = 0; i < nEglija; i++)
        fin >> eglijaMonetos[i];
    fin.close();
}

void keitimas(int nuoNom[], int nuoMon[], int nNuo, int iNom[], int nI, ofstream &fout) {
    int suma = 0;
    for (int i = 0; i < nNuo; i++)
        suma += nuoNom[i] * nuoMon[i];
    if (suma > 3000)
        suma = 3000;
    int kiekiai[MAX_N] = {0};
    int totalCoins = 0;
    for (int i = 0; i <= nI; i++) {
        kiekiai[i] = suma / iNom[i];
        suma %= iNom[i];
        totalCoins+= kiekiai[i];
    }
    for (int i = 0; i < nI; i++)
        fout << iNom[i] << " " << kiekiai[i] << endl;
    fout << totalCoins << endl;
}

int main() {
    skaitytiDuomenis();
    ofstream fout("U1rez.txt");
    keitimas(gilijaNominalai, gilijaMonetos, nGilija, eglijaNominalai, nEglija, fout);
    keitimas(eglijaNominalai, eglijaMonetos, nEglija, gilijaNominalai, nGilija, fout);
    fout.close();
    return 0;
}
