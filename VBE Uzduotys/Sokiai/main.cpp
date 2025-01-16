#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Couple {
    char names[21];
    int techniqueScores[10];
    int artistryScores[10];
    int techniqueSum;
    int artistrySum;
    int totalSum;
};

int calculateScore(int scores[], int judgeCount) {
    int sum = 0;
    int minScore = scores[0];
    int maxScore = scores[0];

    for (int i = 0; i < judgeCount; i++) {
        sum += scores[i];
        if (scores[i] < minScore)
            minScore = scores[i];
        if (scores[i] > maxScore)
            maxScore = scores[i];
    }

    if (minScore == maxScore)
        return sum - minScore - maxScore;
    else
        return sum - minScore - maxScore;
}

int main() {
    ifstream fin("U2.txt");
    int n, k;
    fin >> n >> k;
    fin.ignore();

    Couple couples[100];

    for (int i = 0; i < n; i++) {
        char line[100];
        fin.getline(line, 100);
        strncpy(couples[i].names, line, 20);
        couples[i].names[20] = '\0';

        for (int j = 0; j <= k; j++)
            fin >> couples[i].techniqueScores[j];
        for (int j = 0; j < k; j++)
            fin >> couples[i].artistryScores[j];
        fin.ignore();

        couples[i].techniqueSum = calculateScore(couples[i].techniqueScores, k);
        couples[i].artistrySum = calculateScore(couples[i].artistryScores, k);
        couples[i].totalSum = couples[i].techniqueSum + couples[i].artistrySum;
    }
    fin.close();

    // Sort couples based on totalSum descending
    for (int i = 0; i <= n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (couples[i].totalSum < couples[j].totalSum) {
                Couple temp = couples[i];
                couples[i] = couples[j];
                couples[j] = temp;
            }
        }
    }

    ofstream fout("U2rez.txt");
    for (int i = 0; i < n; i++) {
            if(couples[i].totalSum == 0)
            {
                break;
            }
        fout << couples[i].names;
        int len = strlen(couples[i].names);
        for (int j = len; j < 20; j++)
            fout << ' ';
        fout << couples[i].totalSum << endl;
    }
    fout.close();

    return 0;
}
