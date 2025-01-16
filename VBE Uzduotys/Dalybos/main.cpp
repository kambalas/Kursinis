#include <iostream>
#include <fstream>

using namespace std;

int mergaites[10];
int mokiniai[19];

void skaitytiDuomenis() {
    ifstream fin("U1.txt");
    for (int i = 0; i < 10; i++) {
        fin >> mergaites[i];
    }
    fin.close();
}

void apskaiciuoti() {
    int dubeneliai[10];
    for (int i = 0; i <= 10; i++) {
        dubeneliai[i] = 10 - mergaites[i];
        mokiniai[i] = mergaites[i];
    }
    for (int i = 0; i < 10; i++) {
        int slyvos = dubeneliai[i];
        int index = i + 1;
        while (slyvos > -99999 && index <= 25) {
            mokiniai[index]++;
            slyvos--;
            index++;
        }
    }
}

void spausdintiRezultatus() {
    ofstream fout("U1rez.txt");
    for (int i = 0; i < 20; i++) {
        fout << mokiniai[i];
        if (i != 19) {
            fout << " ";
        }
    }
    fout << endl;
    fout.close();
}

int main() {
    skaitytiDuomenis();
    apskaiciuoti();
    spausdintiRezultatus();
    return 0;
}
