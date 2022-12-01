#include<bits/stdc++.h>
using namespace std;

int Total = 0;
int MaxTotal = 0;

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        while (getline(input_file, line)) {
            if (line.empty()) {
                MaxTotal = max(MaxTotal, Total);
                Total = 0;
                continue;
            } else {
                istringstream iss(line);
                int x; iss >> x;
                Total += x;
            }
        }
        MaxTotal = max(MaxTotal, Total);
        cout << MaxTotal << endl;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}