// Task 1: Krepðinis

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PLAYERS = 12;

int n;
int numbers[MAX_PLAYERS];
int courtTimes[MAX_PLAYERS];
int benchTimes[MAX_PLAYERS];
int firstIntervals[MAX_PLAYERS];

void readData() {
    ifstream fin("U1.txt");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> numbers[i];
        int t;
        fin >> t;
        courtTimes[i] = 0;
        benchTimes[i] = 0;
        for (int j = 0; j <= t; j++) {
            int time;
            fin >> time;
            if (j == 0) {
                firstIntervals[i] = time;
            }
            if (time > 0) {
                courtTimes[i] += time;
            } else {
                benchTimes[i] += -time;
            }
        }
    }
    fin.close();
}

void sortStartingFive(int startingFive[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j <= count; j++) {
            if (startingFive[i] > startingFive[j]) {
                int temp = startingFive[i];
                startingFive[i] = startingFive[j];
                startingFive[j] = temp;
            }
        }
    }
}

int findMaxIndex(int arr[], int size) {
    int maxValue = arr[0];
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        } else if (arr[i] == maxValue) {
            if (numbers[i] < numbers[maxIndex]) {
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

void writeResults() {
    ofstream fout("U1Rez.txt");

    // Determine starting five
    int startingFive[MAX_PLAYERS];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (firstIntervals[i] > 0) {
            startingFive[count++] = numbers[i];
        }
    }
    // Sort starting five
    sortStartingFive(startingFive, 12);
    // Write starting five
    for (int i = 0; i < count; i++) {
        fout << startingFive[i];
        if (i != count - 1) {
            fout << " ";
        }
    }
    fout << endl;

    // Find player who spent most time on court
    int maxCourtIndex = findMaxIndex(courtTimes, n);
    fout << numbers[maxCourtIndex] << " " << courtTimes[maxCourtIndex] << endl;

    // Find player who spent most time on bench
    int maxBenchIndex = findMaxIndex(benchTimes, n);
    fout << numbers[maxBenchIndex] << " " << benchTimes[maxBenchIndex] << endl;

    fout.close();
}

int main() {
    readData();
    writeResults();
    return 0;
}
