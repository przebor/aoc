#include<bits/stdc++.h>
using namespace std;

int Total = 0;

// A overlapuje się z B, gdzie A.first < B.first?
inline bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second >= b.first;
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

                if (c > a) {
                    Total += comp({a, b}, {c, d});
                } else if (c <= a) {
                    Total += comp({c, d}, {a, b});
                }
            }
        }

        cout << Total << endl;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}