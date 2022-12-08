#include<bits/stdc++.h>
using namespace std;

// Bad complexity-wise, but works for such small inputs
// 4*n*n operations, O(n^2)

const int max_n = 100;
int Forest[max_n][max_n];
bool Visible[max_n][max_n];

int Total = 0;
int N;

void stuffs(int begin, int end, bool flip_b = false, bool flip_tab = false) {
    for (int a = begin; a <= end; a++) {
        int h = -1;
        for (int b = (flip_b ? end : begin); (flip_b ? b >= begin : b <= end); b+=(flip_b ? -1 : 1)) {
            int c = (flip_tab ? b : a);
            int d = (flip_tab ? a : b);
            int value = Forest[c][d];
            if (value > h) {
                h = value;
                if (!Visible[c][d]) {
                    Total++;
                }
                Visible[c][d] = true;
            }
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
        stuffs(0, N-1, false, false);
        stuffs(0, N-1, false, true);
        stuffs(0, N-1, true, false);
        stuffs(0, N-1, true, true);


        cout << Total << endl;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}