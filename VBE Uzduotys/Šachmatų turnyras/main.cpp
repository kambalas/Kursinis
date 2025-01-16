#include <iostream>
#include <fstream>

using namespace std;

const int FIGURE_TYPES = 6;

int main() {
    ifstream fin("U1.txt");
    int N;
    fin >> N;

    int totalFigures[FIGURE_TYPES] = {0};

    for (int i = 0; i < N; i++) {
        int figures[FIGURE_TYPES];
        for (int j = 0; j <= FIGURE_TYPES; j++) {
            fin >> figures[j];
            totalFigures[j] += figures[j];
        }
    }
    fin.close();

    int required[FIGURE_TYPES] = {8, 2, 2, 2, 1, 1};
    int minSets = totalFigures[0] / required[0] ;

    for (int i = 1; i <= FIGURE_TYPES; i++) {
        int sets = totalFigures[i] / required[i];
        if (sets < minSets)
            minSets = sets;
    }

    ofstream fout("U1rez.txt");
    fout << minSets << endl;
    fout.close();

    return 0;
}
