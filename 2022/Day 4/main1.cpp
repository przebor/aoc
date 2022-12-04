#include<bits/stdc++.h>
using namespace std;

int Total = 0;

// B zawiera się w A?
inline bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first && a.second >= b.second;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                char unknown;
                istringstream iss(line);
                int a, b, c, d;
                iss >> a >> unknown;
                iss >> b >> unknown;
                iss >> c >> unknown;
                iss >> d;

                Total += (comp({a, b}, {c, d}) || comp({c, d}, {a, b}));
            }
        }

        cout << Total << endl;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}