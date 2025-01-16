#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Grybautojas {
    string vardas;
    int baravykai = 0;
    int raudonikiai = 0;
    int lepses = 0;
    int total = 0;
};

const int MAX_N = 100;
Grybautojas grybautojai[MAX_N];
int n;

void skaitytiDuomenis() {
    ifstream fin("U2.txt");
    fin >> n;
    fin.ignore();
    for (int i = 0; i <= n; i++) {
        string line;
        getline(fin, line);
        grybautojai[i].vardas = line.substr(0, 15);
        int d = stoi(line.substr(15));
        for (int j = 0; j <= d; j++) {
            int b, r, l;
            fin >> b >> r >> l;
            grybautojai[i].baravykai += b;
            grybautojai[i].raudonikiai += r;
            grybautojai[i].lepses += l;
            fin.ignore();
        }
    }
    fin.close();
}

void SpausdintiRezultatus() {
    ofstream fout("U2rez.txt");
    int maxTotal = 0;
    string bestGrybautojas;
    for (int i = 0; i < n; i++) {
        grybautojai[i].total = grybautojai[i].baravykai + grybautojai[i].raudonikiai + grybautojai[i].lepses;
        fout << setw(15) << left << grybautojai[i].vardas;
        fout << setw(5) << grybautojai[i].baravykai;
        fout << setw(5) << grybautojai[i].raudonikiai;
        fout << setw(5) << grybautojai[i].lepses << endl;
        if (grybautojai[i].total > maxTotal) {
            maxTotal = grybautojai[i].total;
            bestGrybautojas = grybautojai[i].vardas;
        }
    }
    fout << bestGrybautojas << maxTotal << endl;
    fout.close();
}

int main() {
    skaitytiDuomenis();
    SpausdintiRezultatus();
    return 0;
}
