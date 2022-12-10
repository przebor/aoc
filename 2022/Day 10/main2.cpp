#include<bits/stdc++.h>
using namespace std;

int Cycle = 0;
int Xreg = 1;

int Cursor = 1;

inline void incr_cycle() { 
    Cursor = (Cycle) % 40;
    Cycle++;
    if (abs(Xreg - Cursor) <= 1) cout << "#";
    else cout << ".";
    if (Cursor == 39) cout << endl;
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
                    incr_cycle();
                } else {
                    incr_cycle();
                    incr_cycle();
                    int V; iss >> V;
                    Xreg += V;
                }
            }
        }

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}