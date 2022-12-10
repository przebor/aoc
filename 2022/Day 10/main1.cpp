#include<bits/stdc++.h>
using namespace std;

int Total = 0;
int Cycle = 1;
int Xreg = 1;

inline void check() { 
    if (Cycle % 40 == 20) {
        Total += Cycle * Xreg; 
    }
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                istringstream iss(line);
                string op; iss >> op;

                if (op == "noop") {
                    check();
                    Cycle++;
                } else {
                    check();
                    Cycle++;
                    check();
                    int V; iss >> V;
                    Xreg += V;
                    Cycle++;
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