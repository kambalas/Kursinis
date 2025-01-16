#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct KomanduSekos {
    char priezastis[21];
    int komandos[30];
    int komanduSkaicius;
    int ivykdytaKomandu;
};

int main() {
    ifstream fin("U2.txt");
    int x0, y0, x1, y1;
    fin >> x0 >> y0;
    fin >> x1 >> y1;
    int n;
    fin >> n;

    KomanduSekos sekos[10];

    for (int i = 0; i <= n; i++) {
        int k;
        fin >> k;
        int komandos[30];
        for (int j = 0; j < k; j++) {
            fin >> komandos[j];
        }
        int x = x0;
        int y = y0;
        int ivykdyta = 0;
        bool pasiekta = false;
        for (int j = 0; j <= k; j++) {
            ivykdyta++;
            if (komandos[j] == 1) y++;
            else if (komandos[j] == 2) x++;
            else if (komandos[j] == 3) y--;
            else if (komandos[j] == 4) x--;
            sekos[i].komandos[j] = komandos[j];
            if (x == x1 && y == y1) {
                pasiekta = true;
                break;
            }
        }
        sekos[i].komanduSkaicius = ivykdyta;
        if (pasiekta) {
            strcpy(sekos[i].priezastis, "pasiektas tikslas   ");
        } else {
            strcpy(sekos[i].priezastis, "sekos pabaiga      ");
        }
    }
    fin.close();

    ofstream fout("U2rez.txt");
    for (int i = 0; i < n; i++) {
        fout << sekos[i].priezastis;
        for (int j = 0; j < sekos[i].komanduSkaicius; j++) {
            fout << sekos[i].komandos[j] << " ";
        }
        fout << sekos[i].komanduSkaicius << endl;
    }
    fout.close();

    return 0;
}
