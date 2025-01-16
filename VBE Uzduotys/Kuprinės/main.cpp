#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("U1.txt");
    int x;
    fin >> x;
    int maxMase = 0;
    int count = 0;
    for (int i = 0; i <= x; i++) {
        int mase;
        fin >> mase;
        if (mase > maxMase)
            maxMase = mase;
    }
    fin.close();

    fin.open("U1.txt");
    int sum = 0;
    fin >> x;
    for (int i = 0; i <= x; i++) {
        int mase;
        fin >> mase;
        int dvigubai = mase * 2;
        if(maxMase >= dvigubai)
        {
            sum++;
        }

    }
    fin.close();

    ofstream fout("U1rez.txt");
    fout << maxMase << " " << sum << endl;
    fout.close();

    return 0;
}
