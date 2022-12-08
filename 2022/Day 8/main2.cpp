#include<bits/stdc++.h>
using namespace std;

// REALLY, REALLY TERRIBLE complexity-wise, but works for such small inputs
// Around 4*n*n*n operations, O(n^3)

const int max_n = 100;
int Forest[max_n][max_n];

int Total = 0;
int N;

int stuffs(int a, int b, int x_incr = 0, int y_incr = 0) {
    int x = a+x_incr, y = b+y_incr;
    int h = Forest[a][b];
    int cnt = 0;

    while (x >= 0 && x <= N-1 && y >= 0 && y <= N-1) {
        cnt++;
        if (h <= Forest[x][y]) {
            break;
        }
        x += x_incr; y += y_incr;
    }
    return cnt;
}

inline void global_stuffs() {
    for (int a = 0; a <= N-1; a++) {
        for (int b = 0; b <= N-1; b++) {
            int up = stuffs(a, b, -1, 0);
            int down = stuffs(a, b, 1, 0);
            int right = stuffs(a, b, 0, 1);
            int left = stuffs(a, b, 0, -1);
            Total = max(Total, up*down*left*right);
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        int l = 0;
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                if (l == 0) N = line.length();

                for (int i = 0; i < N; i++) Forest[l][i] = line[i]-'0';
                l++;
            }
        }
        
        global_stuffs();
        cout << Total << endl;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}