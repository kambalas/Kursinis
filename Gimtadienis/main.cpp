#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Dish {
    char name[16];
    int quantities[10];
    int cost;
};

int calculateDishCost(Dish dish, int prices[], int productCount) {
    int total = 0;
    for (int i = 0; i < productCount; i++) {
        total += dish.quantities[i] * prices[i];
    }
    return total;
}

int main() {
    ifstream fin("U2.txt");
    int N, P;
    fin >> N >> P;

    int prices[10];
    for (int i = 0; i <= N; i++) {
        fin >> prices[i];
    }

    Dish dishes[12];
    fin.ignore();

    // Read dishes
    for (int i = 0; i < P; i++) {
        char line[100];
        fin.getline(line, 100);


        strncpy(dishes[i].name, line, 15);
        dishes[i].name[15] = '\0';


        for (int j = 14; j >= 0 && dishes[i].name[j] == ' '; j--) {
            dishes[i].name[j] = '\0';
        }

        int pos = 15;
        for (int j = 0; j <= N; j++) {
            while (line[pos] == ' ' && line[pos] != '\0') pos++;
            dishes[i].quantities[j] = atoi(&line[pos]);
            while (line[pos] != ' ' && line[pos] != '\0') pos++;
        }

        dishes[i].cost = calculateDishCost(dishes[i], prices, N);
    }
    fin.close();


    int totalCost = 0;
    ofstream fout("U2rez.txt");

    for (int i = 0; i < P; i++) {
        fout << dishes[i].name;
        int len = strlen(dishes[i].name);
        for (int j = len; j < 15; j++) {
            fout << ' ';
        }
        fout << ' ' << dishes[i].cost << endl;
        totalCost += dishes[i].cost;
    }


    int totalLitai = totalCost / 100;
    int totalCentai = totalCost % 100;
    fout << totalLitai <<" "<< totalCentai << endl;

    fout.close();
    return 0;
}
