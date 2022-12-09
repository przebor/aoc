#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> Visited;
vector<pair<int, int>> Knots;

int Total = 0;

// {X, Y} where X is left(1)-right(-1), Y is up(1)-down(-1)

void update_knots() {
    for (int i = 1; i < Knots.size(); i++) {
        pair<int, int> Knot = Knots[i];
        pair<int, int> Prev_knot = Knots[i-1];

        if (abs(Prev_knot.first - Knot.first) >= 2 && abs(Prev_knot.second - Knot.second) >= 2) {
            Knot.first += (Prev_knot.first - Knot.first >= 2 ? 1 : -1);
            Knot.second += (Prev_knot.second - Knot.second >= 2 ? 1 : -1);
        } else if (Prev_knot.first - Knot.first >= 2) {
            Knot.first++;
            Knot.second = Prev_knot.second;
        } else if (Prev_knot.first - Knot.first <= -2) {
            Knot.first--;
            Knot.second = Prev_knot.second;
        } else if (Prev_knot.second - Knot.second >= 2) {
            Knot.second++;
            Knot.first = Prev_knot.first;
        } else if (Prev_knot.second - Knot.second <= -2) {
            Knot.second--;
            Knot.first = Prev_knot.first;
        }

        if (i == Knots.size()-1 && Visited.count(Knot) == 0) {
            Visited.insert(Knot);
            Total++;
        }
        Knots[i] = Knot;
        Knots[i-1] = Prev_knot;
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        for (int i = 0; i < 10; i++) Knots.push_back({0, 0});
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
                    if (c == 'U') Knots[0].second++;
                    else if (c == 'D') Knots[0].second--;
                    else if (c == 'R') Knots[0].first++;
                    else if (c == 'L') Knots[0].first--;

                    update_knots();
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