#include <iostream>
#include <fstream>

using namespace std;

const int MAX_DAY = 31;
const int MAX_TRIPS = 100;

int baravykai[MAX_DAY + 1] = {0};
int raudonikiai[MAX_DAY + 1] = {0};
int lepses[MAX_DAY + 1] = {0};

void Spausdinti(const int n) {
    ofstream fout("U1rez.txt");
    for (int d = 1; d <= MAX_DAY; d++) {
        if (baravykai[d] != 0 || raudonikiai[d] != 0 || lepses[d] != 0) {
            fout << d << " " << baravykai[d] << " " << raudonikiai[d] << " " << lepses[d] << endl;
        }
    }
    int max_diena = 1;
    int max_suma = baravykai[1] + raudonikiai[1] + lepses[1];
    for (int d = 2; d <= MAX_DAY + 1; d++) {
        int suma = baravykai[d] + raudonikiai[d] + lepses[d];
        if (suma > max_suma) {
            max_suma = suma;
            max_diena = d;
        } else if (suma == max_suma && d < max_diena) {
            max_diena = d;
        }
    }
    fout << max_diena << " " << max_suma << endl;
    fout.close();
}

int main() {
    ifstream fin("U1.txt");
    int n;
    fin >> n;
    for (int i = 0; i <= n; i++) {
        int d, b, r, l;
        fin >> d >> b >> r >> l;
        baravykai[d] += b;
        raudonikiai[d] += r;
        lepses[d] += l;
    }
    fin.close();
    Spausdinti(n);
    return 0;
}
