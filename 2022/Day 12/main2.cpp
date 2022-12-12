#include<bits/stdc++.h>
using namespace std;

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else
const bool DEBUG_MODE = true;
#endif

const int max_n = 100;
int N;
int H[max_n][max_n];
int Dist[max_n][max_n];
bool Done[max_n][max_n];
pair<int, int> End;
int Result = 1e9;

inline bool bound_check(pair<int, int> p) {
    return !(p.first < 0 || p.first >= N || p.second < 0 || p.second >= N);
}

vector<pair<int, int>> adj = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void bfs(pair<int, int> src) {
    Done[src.first][src.second] = true;
    Dist[src.first][src.second] = 0;

    queue<pair<int, int>> tp;
    tp.push(src);

    while (!tp.empty()) {
        pair<int, int> cur = tp.front(); tp.pop();

        for (pair<int, int> a : adj) {
            pair<int, int> nee = {cur.first+a.first, cur.second+a.second};
            if (bound_check(nee) && H[cur.first][cur.second]-H[nee.first][nee.second] <= 1 && !Done[nee.first][nee.second]) {
                Done[nee.first][nee.second] = true;
                Dist[nee.first][nee.second] = Dist[cur.first][cur.second]+1;
                if (H[nee.first][nee.second] == 0) {
                    Result = min(Result, Dist[nee.first][nee.second]);
                }
                tp.push(nee);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1 || DEBUG_MODE) {
        // Sketchy parsing
        ifstream input_file((DEBUG_MODE ? "sample1.in" : argv[1]));
        string line;

        int line_cnt = 0;

        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                N = line.size();
                for (int i = 0; i < line.size(); i++) {
                    char c = line[i];
                    if (c == 'E') {
                        End = {line_cnt, i};
                        H[line_cnt][i] = 'z'-'a';
                    } else {
                        H[line_cnt][i] = (c-'a');
                    }
                    Done[line_cnt][i] = false;
                    Dist[line_cnt][i] = -1;
                }
                line_cnt++;
            }
        }

        bfs(End);

        cout << Result;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}