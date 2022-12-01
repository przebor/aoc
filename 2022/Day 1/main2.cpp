#include<bits/stdc++.h>
using namespace std;

multiset<int, greater<int>> Calories;
int Total = 0;

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                Calories.insert(Total);
                Total = 0;
                continue;
            } else {
                istringstream iss(line);
                int x; iss >> x;
                Total += x;
            }
        }
        
        Total = 0;
        for (int i = 0; i < 3; i++) {
            Total += *Calories.begin();
            Calories.erase(Calories.begin());
        }
        cout << Total << endl;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}