#include <iostream>
#include <fstream>

using namespace std;

struct Glove {
    int type; // 3 - male, 4 - female
    int hand; // 1 - left, 2 - right
    int size;
};

int main() {
    ifstream fin("U1.txt");
    int n;
    fin >> n;

    const int MAX_SIZE = 100;
    int maleLeft[MAX_SIZE] = {0};
    int maleRight[MAX_SIZE] = {0};
    int femaleLeft[MAX_SIZE] = {0};
    int femaleRight[MAX_SIZE] = {0};

    for (int i = 0; i <= n; i++) {
        Glove glove;
        fin >> glove.type >> glove.hand >> glove.size;
        int index = glove.size;

        if (glove.type == 3) {
            if (glove.hand == 1)
                maleLeft[index]++;
            else
                maleRight[index]++;
        } else {
            if (glove.hand == 1)
                femaleLeft[index]++;
            else
                femaleRight[index]++;
        }
    }
    fin.close();

    int malePairs = 0, femalePairs = 0;
    int maleLeftover = 0, femaleLeftover = 0;

    for (int i = 0; i <= MAX_SIZE; i++) {
        int malePair = min(maleLeft[i], maleRight[i]);
        malePairs += malePair;
        maleLeftover += (maleLeft[i] + maleRight[i]) - 2 * malePair;

        int femalePair = min(femaleLeft[i], femaleRight[i]);
        femalePairs += femalePair;
        femaleLeftover += (femaleLeft[i] + femaleRight[i]) - 2 * femalePair;
    }

    ofstream fout("U1rez.txt");
    fout << femalePairs << endl << malePairs << endl << femaleLeftover << endl << maleLeftover << endl;

    fout.close();

    return 0;
}
