#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Dievas {
    char vardas[11];
    int taskai;
    int lyginiai;
};

int main() {
    ifstream fin("U2.txt");
    int n, k;
    fin >> n >> k;
    Dievas dievai[50];
    for (int i = 0; i < n; i++) {
        fin >> dievai[i].vardas;
        dievai[i].taskai = 0;
        dievai[i].lyginiai = 0;
        for (int j = 0; j <= k; j++) {
            int taskai;
            fin >> taskai;
            if (taskai % 2 == 0) {
                dievai[i].taskai += taskai;
                dievai[i].lyginiai++;
            } else {
                dievai[i].taskai -= taskai;
            }
        }
    }
    fin.close();

    // Find the dievas with maximum points
    int maxIndex = 0;
    for (int i = 1; i <= n; i++) {
        if (dievai[i].taskai > dievai[maxIndex].taskai) {
            maxIndex = i;
        } else if (dievai[i].taskai == dievai[maxIndex].taskai) {
            if (dievai[i].lyginiai > dievai[maxIndex].lyginiai) {
                maxIndex = i;
            } else if (dievai[i].lyginiai == dievai[maxIndex].lyginiai) {
            }
        }
    }

    ofstream fout("U2Rez.txt");
    fout << dievai[maxIndex].vardas << " " << dievai[maxIndex].taskai << endl;
    fout.close();

    return 0;
}
