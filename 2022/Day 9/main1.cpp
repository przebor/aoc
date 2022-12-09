#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> Visited;
pair<int, int> H;
pair<int, int> T;

int Total = 0;

// {X, Y} where X is left(1)-right(-1), Y is up(1)-down(-1)

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        Visited.insert({0, 0});
        Total++;

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                istringstream iss(line);
                char c; int amount; iss >> c >> amount;

                for (int i = 0; i < amount; i++) {
                    if (c == 'U') H.second++;
                    else if (c == 'D') H.second--;
                    else if (c == 'R') H.first++;
                    else if (c == 'L') H.first--;

                    if (H.first - T.first >= 2) {
                        T.first++;
                        T.second = H.second;
                    } else if (H.first - T.first <= -2) {
                        T.first--;
                        T.second = H.second;
                    } else if (H.second - T.second >= 2) {
                        T.second++;
                        T.first = H.first;
                    } else if (H.second - T.second <= -2) {
                        T.second--;
                        T.first = H.first;
                    }

                    if (Visited.count(T) == 0) {
                        Visited.insert(T);
                        Total++;
                    }
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