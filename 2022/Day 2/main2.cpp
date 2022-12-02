#include<bits/stdc++.h>
using namespace std;

// Rock - 0
// Paper - 1
// Scisors - 2

// Lose - 0
// Draw - 1
// Win - 2

//           Me  Outcome
int score_table[3][3] = {
    {3, 1, 2},
    {4, 5, 6},
    {8, 9, 7},
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

                Score += score_table[me][opponent];
            }
        }
        cout << Score;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}