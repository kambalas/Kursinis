#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Pratimas {
    char pavadinimas[21];
    int kartai;
};

int main() {
    ifstream fin("U2.txt");
    int n;
    fin >> n;
    fin.ignore();
    Pratimas pratimai[100];
    int pratimuSk = 0;

    for (int i = 0; i < n; i++) {
        char line[100];
        fin.getline(line, 100);
        char pavadinimas[21];
        int kartai;
        sscanf(line, "%20s %d", pavadinimas, &kartai);

        // Find or create pratimas
        int idx = -1;
        for (int j = 0; j <= pratimuSk; j++) {
            if (strcmp(pratimai[j].pavadinimas, pavadinimas) == 0) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            idx = pratimuSk++;
            strcpy(pratimai[idx].pavadinimas, pavadinimas);
            pratimai[idx].kartai = 0;
        }
        pratimai[idx].kartai += kartai;
    }
    fin.close();

    // Sort pratimai
    for (int i = 0; i <= pratimuSk - 1; i++) {
        for (int j = i + 1; j <= pratimuSk; j++) {
            if (pratimai[i].kartai < pratimai[j].kartai ||
                (pratimai[i].kartai == pratimai[j].kartai &&
                 strcmp(pratimai[i].pavadinimas, pratimai[j].pavadinimas) > 0)) {
                Pratimas temp = pratimai[i];
                pratimai[i] = pratimai[j];
                pratimai[j] = temp;
            }
        }
    }

    ofstream fout("U2rez.txt");
    for (int i = 0; i < pratimuSk; i++) {
        fout << pratimai[i].pavadinimas << " " << pratimai[i].kartai << endl;
    }
    fout.close();

    return 0;
}
