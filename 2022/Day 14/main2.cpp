#include<bits/stdc++.h>
using namespace std;

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else
const bool DEBUG_MODE = true;
#endif

// Kind of a hacky modification to Part 1

const int max_n = 1e4;
int Grid[max_n][max_n];
int high_y = -1;

void fill(pair<int, int> from, pair<int, int> to) {
    if (from.first == to.first) {
        if (from.second > to.second) swap(from, to);

        for (int i = from.second; i <= to.second; i++) {
            Grid[from.first][i] = 1;
        }
    } else if (from.second == to.second) {
        if (from.first > to.first) swap(from, to);

        for (int i = from.first; i <= to.first; i++) {
            Grid[i][from.second] = 1;
        }
    }
}

void simulate_sand() {
    pair<int, int> pos = {500,0};

    bool br = false;

    while (!br) {
        if (Grid[pos.first][pos.second+1] == 0) {
            pos.second++;
        } else if (Grid[pos.first-1][pos.second+1] == 0) {
            pos.first--;
            pos.second++;
        } else if (Grid[pos.first+1][pos.second+1] == 0) {
            pos.first++;
            pos.second++;
        } else {
            br = true;
            Grid[pos.first][pos.second] = -1;
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1 || DEBUG_MODE) {
        // Sketchy parsing
        ifstream input_file((DEBUG_MODE ? "sample1.in" : argv[1]));
        string line;

        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                pair<int, int> a = {-1, -1};
                pair<int, int> b = {-1, -1};
                string cur_num;
                bool on_x = true;

                for (char c : line) {
                    if (c == ' ' || c == '>') continue;
                    if (c == ',') {
                        int num = stoi(cur_num);
                        if (b.second == -1) {
                            b.first = num;
                        } else {
                            a = {b.first, b.second};
                            b.first = num;
                        }

                        cur_num = "";
                    } else if (c == '-') {
                        int num = stoi(cur_num);
                        b.second = num;    
                        high_y = max(high_y, b.second);

                        cur_num = "";
                        if (a.second != -1) fill(a, b);
                    } else {
                        cur_num += c;
                    }
                }

                int num = stoi(cur_num);
                b.second = num;    

                cur_num = "";
                fill(a, b);
            }
        }

        for (int x = 0; x <= max_n; x++) Grid[x][high_y+2] = 1;

        int cnt = 0;
        while (Grid[500][0] != -1) {
            simulate_sand();
            cnt++;
        }

        cout << cnt << endl;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}