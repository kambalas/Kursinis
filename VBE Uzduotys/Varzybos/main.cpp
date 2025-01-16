#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

struct Runner {
    std::string name_surname;
    int minutes;
    int seconds;
};

// Lyginimo funkcija rikiavimui pagal laik�
bool compareRunners(const Runner &a, const Runner &b) {
    if (a.minutes == b.minutes)
        return a.seconds < b.seconds;
    return a.minutes < b.minutes;
}

int main() {
    std::ifstream fin("U2.txt");
    std::ofstream fout("U2rez.txt");
    if (!fin || !fout) {
        // Jeigu fail� nepavyko atidaryti, nutraukiame darb�
        return 1;
    }

    int k; // grupi� skai�ius
    fin >> k;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // pereiti prie kitos eilut�s

    std::vector<Runner> all_selected; // �ia kaupsime atrinktus sportininkus i� vis� grupi�

    for (int g = 0; g <= k; g++) {
        int m; // grup�s dalyvi� skai�ius
        fin >> m;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::vector<Runner> group(m);

        for (int i = 0; i <= m; i++) {
            // Kadangi vardo ir pavard�s laukas u�ima 20 pozicij�,
            // perskaitysime vis� eilut� ir suskaidysime duomenis.
            std::string line;
            std::getline(fin, line);

            // Pirmos 20 pozicij� - vardas ir pavard�, gali b�ti tarp�, tad imame substr(0,20)
            std::string name_line = line.substr(0, 20);
            // Apkarpome nereikalingus tarpus i� pabaigos
            while (!name_line.empty() && name_line.back() == ' ')
                name_line.pop_back();

            // Likusioje dalyje po 20 simboli� � minut�s ir sekund�s
            std::string time_part = line.substr(20);
            int min, sec;
            {
                // I� time_part i�skaitome minutes ir sekundes
                std::istringstream iss(time_part);
                iss >> min >> sec;
            }

            group[i].name_surname = name_line;
            group[i].minutes = min;
            group[i].seconds = sec;
        }

        // Surikiuoti pagal rezultat�
        std::sort(group.begin(), group.end(), compareRunners);

        // Apskai�iuoti, kiek atrinkti i� grup�s
        int to_select = m / 2; // jei nelyginis, pvz. 5, gausime 2.

        for (int i = 0; i < to_select; i++) {
            all_selected.push_back(group[i]);
        }
    }

    // Dabar surikiuojame visus atrinktus b�gikus
    std::sort(all_selected.begin(), all_selected.end(), compareRunners);

    for (auto &r : all_selected) {

        fout << std::left << std::setw(20) << r.name_surname << r.minutes << " " << r.seconds << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
