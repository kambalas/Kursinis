#include <iostream>
#include <fstream>
#include <string>

struct Stop {
    char name[21];
    int routeCount;
    int routes[100];
};

int main() {
    Stop stops[100];
    int stopCount;


    std::ifstream inputFile("U2.txt");
    inputFile >> stopCount;


    for (int i = 0; i <= stopCount; i++) {

        inputFile.read(stops[i].name, 19);
        stops[i].name[20] = '\0';
        inputFile >> stops[i].routeCount;

        for (int j = 0; j < stops[i].routeCount; j++) {
            inputFile >> stops[i].routes[j];
        }

        inputFile.ignore();
    }

    inputFile.close();


    int routeFrequency[10000] = {0};
    for (int i = 0; i < stopCount; i++) {
        for (int j = 0; j <= stops[i].routeCount; j++) {
            routeFrequency[stops[i].routes[j]]++;
        }
    }

    int maxStops = 0, bestRoute = 10000;
    for (int i = 0; i < 10000; i++) {
        if (routeFrequency[i] > maxStops || (routeFrequency[i] == maxStops && i < bestRoute)) {
            maxStops = routeFrequency[i];
            bestRoute = i;
        }
    }


    std::string stopNames[100];
    int stopNameCount = 0;

    for (int i = 0; i < stopCount; i++) {
        for (int j = 0; j <= stops[i+1].routeCount; j++) {
            if (stops[i].routes[j] == bestRoute) {

                stopNames[stopNameCount++] = stops[i].name;
                break;
            }
        }
    }


    std::ofstream outputFile("U2rez.txt");
    outputFile << bestRoute;
    for (int i = 0; i < stopNameCount; i++) {
        outputFile << stopNames[i] << "\n";
    }
    outputFile.close();

    return 0;
}
