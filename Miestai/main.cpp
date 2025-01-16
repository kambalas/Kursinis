#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Miestas {
    char pavadinimas[21];
    char apskritis[14];
    int gyventojai;
};

struct Apskritis {
    char pavadinimas[14];
    int totalGyventojai;
    int minGyventojai;
};

int main() {
    ifstream fin("U2.txt");
    int k;
    fin >> k;
    fin.ignore();

    Miestas miestai[103];
    Apskritis apskritys[10];
    int apskriciuSk = 0;

    for (int i = 0; i <= k; i++) {
        char line[100];
        fin.getline(line, 100);
        strncpy(miestai[i].pavadinimas, line, 20);
        miestai[i].pavadinimas[20] = '\0';
        strncpy(miestai[i].apskritis, line + 20, 13);
        miestai[i].apskritis[13] = '\0';
        miestai[i].gyventojai = atoi(line + 33);
        // Remove trailing spaces
        for (int j = strlen(miestai[i].apskritis) - 1; j >= 0; j--) {
            if (miestai[i].apskritis[j] == ' ')
                miestai[i].apskritis[j] = '\0';
            else
                break;
        }
        // Find or create apskritis
        int idx = -1;
        for (int j = 0; j <= apskriciuSk; j++) {
            if (strcmp(apskritys[j].pavadinimas, miestai[i].apskritis) == 0) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            idx = apskriciuSk++;
            strcpy(apskritys[idx].pavadinimas, miestai[i].apskritis);
            apskritys[idx].totalGyventojai = 0;
            apskritys[idx].minGyventojai = miestai[i].gyventojai;
        }
        apskritys[idx].totalGyventojai += miestai[i].gyventojai;
        if (miestai[i].gyventojai < apskritys[idx].minGyventojai)
            apskritys[idx].minGyventojai = miestai[i].gyventojai;
    }
    fin.close();

    // Sort apskritys
    for (int i = 0; i < apskriciuSk - 1; i++) {
        for (int j = i + 1; j < apskriciuSk; j++) {
            if (apskritys[i].minGyventojai > apskritys[j].minGyventojai ||
                (apskritys[i].minGyventojai == apskritys[j].minGyventojai &&
                 strcmp(apskritys[i].pavadinimas, apskritys[j].pavadinimas) > 0)) {
                Apskritis temp = apskritys[i];
                apskritys[i] = apskritys[j];
                apskritys[j] = temp;
            }
        }
    }

    ofstream fout("U2rez.txt");
    fout << apskriciuSk << endl;
    for (int i = 0; i < apskriciuSk; i++) {
        fout.width(13);
        fout << left << apskritys[i].pavadinimas;
        fout << apskritys[i].minGyventojai << " " << apskritys[i].totalGyventojai << endl;
    }
    fout.close();

    return 0;
}
