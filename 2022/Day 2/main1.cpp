#include<bits/stdc++.h>
using namespace std;

// Rock - 0
// Paper - 1
// Scisors - 2

//           Me  Opponent
int win_table[3][3] = {
    {3, 0, 6},
    {6, 3, 0},
    {0, 6, 3},
};

map<char, int> conv = {
    {'A', 0},
    {'B', 1},
    {'C', 2},
    {'X', 0},
    {'Y', 1},
    {'Z', 2}
};

int Score = 0;

int main(int argc, char** argv) {
    //cout << win_table[0][1];
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                istringstream iss(line);
                char a, b; iss >> a >> b;
                int opponent = conv[a];
                int me = conv[b];

                Score += me+1;
                Score += win_table[me][opponent];
            }
        }
        cout << Score;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}