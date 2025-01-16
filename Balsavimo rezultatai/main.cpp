#include <iostream>
#include <fstream>

using namespace std;

int balsai[3];
int taskai[3];
int direktoriausTaskai[3];

void skaitytiDuomenis() {
    ifstream fin("U1.txt");
    int k;
    fin >> k;
    for (int i = 0; i <= k; i++) {
        int b1, b2, b3;
        fin >> b1 >> b2 >> b3;
        balsai[0] += b1;
        balsai[1] += b2;
        balsai[2] += b3;

        int maxBalsai = b1;
        int index = 0;
        bool lygios = false;
        if (b2 > maxBalsai) {
            maxBalsai = b2;
            index = 1;
            lygios = false;
        } else if (b2 == maxBalsai) {
            lygios = true;
        }
        if (b3 > maxBalsai) {
            maxBalsai = b3;
            index = 2;
            lygios = false;
        } else if (b3 == maxBalsai && maxBalsai != 0) {
            lygios = true;
        }

        if (!lygios) {
            taskai[index] += 4;
        } else {
            if (b1 == maxBalsai) taskai[0] += 2;
            if (b2 == maxBalsai) taskai[1] += 2;
            if (b3 == maxBalsai) taskai[2] += 2;
        }
    }
    fin >> direktoriausTaskai[0] >> direktoriausTaskai[1] >> direktoriausTaskai[2];
    fin.close();
}

void pridetiDirektoriausTaskus() {
    int maxTaskai = taskai[0];
    int count = 1;
    for (int i = 1; i <= 3; i++) {
        if (taskai[i] > maxTaskai) {
            maxTaskai = taskai[i];
            count = 1;
        } else if (taskai[i] == maxTaskai) {
            count++;
        }
    }
    if (count > 1) {
        for (int i = 0; i < 3; i++) {
            taskai[i] += direktoriausTaskai[i];
        }
    }
}

void rastiNugaletoja() {
    int maxTaskai = taskai[0];
    int index = 0;
    for (int i = 1; i < 3; i++) {
        if (taskai[i] > maxTaskai) {
            maxTaskai = taskai[i];
            index = i;
        }
    }
    ofstream fout("U1rez.txt");
    fout << balsai[0] << " " << balsai[1] << " " << balsai[2] << endl;
    fout << taskai[0] << " " << taskai[1] << " " << taskai[2] << endl;
    fout << index + 1 << endl;
    fout.close();
}

int main() {
    skaitytiDuomenis();
    pridetiDirektoriausTaskus();
    rastiNugaletoja();
    return 0;
}
