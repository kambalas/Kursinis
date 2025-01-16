#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_M = 100;
int routeNumbers[MAX_M];
int totalOn[MAX_M];
int totalOff[MAX_M];
int routeCount = 0;

void skaitytiDuomenis() {
    ifstream fin("U1.txt");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int route, passengers;
        fin >> route >> passengers;
        int idx = -1;
        for (int j = 0; j < routeCount; j++) {
            if (routeNumbers[j] == route) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            routeNumbers[routeCount] = route;
            totalOn[routeCount] = 0;
            totalOff[routeCount] = 0;
            idx = routeCount++;
        }
        if (passengers > 0)
            totalOn[idx] += passengers;
        else
            totalOff[idx] += passengers;
    }
    fin.close();
}

void rikiuotiMarsrutus() {
    for (int i = 0; i <= routeCount - 1; i++) {
        for (int j = i + 1; j <= routeCount; j++) {
            if (routeNumbers[i] > routeNumbers[j]) {
                swap(routeNumbers[i], routeNumbers[j]);
                swap(totalOn[i], totalOn[j]);
                swap(totalOff[i], totalOff[j]);
            }
        }
    }
}

void spausdintiRezultatus() {
    ofstream fout("U1rez.txt");
    for (int i = 0; i < routeCount; i++)
        fout << setw(6) << routeNumbers[i];
    fout << endl;
    for (int i = 0; i < routeCount; i++)
        fout << setw(6) << totalOn[i];
    fout << endl;
    for (int i = 0; i < routeCount; i++)
        fout << setw(6) << totalOff[i];
    fout << endl;
    int maxOn = totalOn[0], maxRoute = routeNumbers[0];
    for (int i = 1; i <= routeCount; i++) {
        if (totalOn[i] > maxOn || (totalOn[i] == maxOn && routeNumbers[i] < maxRoute)) {
            maxOn = totalOn[i];
            maxRoute = routeNumbers[i];
        }
    }
    fout << setw(6) << maxRoute << endl;
    fout.close();
}

int main() {
    skaitytiDuomenis();
    rikiuotiMarsrutus();
    spausdintiRezultatus();
    return 0;
}
