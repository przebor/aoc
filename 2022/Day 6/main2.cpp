#include<bits/stdc++.h>
using namespace std;

string line;
int N = 14;

bool check_from(int f) {
    set<char> woo;

    for (int i = f; i < f+N; i++) {
        if (woo.count(line[i]) > 0) {
            return 0;
        } 
        woo.insert(line[i]);
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                for (int a = 0; a <= line.length()-N; a++) {
                    if (check_from(a)) {
                        cout << a+N;
                        return 1;
                    }
                }
            }
        }
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}