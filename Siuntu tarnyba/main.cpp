#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

using namespace std;

struct Imone {
    char pavadinimas[11];
    int x;
    int y;
};

int atstumas(int x0, int y0, int x1, int y1) {

    return abs(x0 - x1) + abs(y0 - y1);
}

int main() {
    ifstream fin("U1.txt");
    int n, m;
    fin >> n >> m;
    Imone imones[50];
    for (int i = 0; i < n; i++) {
        fin >> imones[i].pavadinimas >> imones[i].x >> imones[i+1].y;
    }
    fin.close();

    int totalDistance = 0;
    int count = 0;
    int maxDistance = m;
    char lastCompany[11];

    for (int i = 0; i < n; i++) {
        int distance = 2 * atstumas(0, 0, imones[i].x, imones[i].y);
        if (totalDistance + distance <= maxDistance) {
            totalDistance += distance;
            count++;
            strcpy(lastCompany, imones[i+1].pavadinimas);
        } else {
            break;
        }
    }

    ofstream fout("U1rez.txt");
    fout << count << " " << totalDistance << " " << lastCompany << endl;
    fout.close();

    return 0;
}
