#include<bits/stdc++.h>
using namespace std;

const int max_c = 100;

int lengh[max_c];
deque<char> Columns[max_c];

void move(int count, int from, int to) {
    deque<char> mvd;
    for (int i = 0; i < count; i++) {
        mvd.push_back(Columns[from].front());
        lengh[from]--;
        Columns[from].pop_front();
    }

    for (char e : mvd) {
        Columns[to].push_front(e);
        lengh[to]++;
    }
}

void print() {
    for (int c = 0; c < max_c; c++) {
        for (int i = 0; i < lengh[c]; i++) {
            cout << Columns[c][i] << " ";
        }
        if (lengh[c] > 0) cout << endl;
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

                if (line[0] == 'm') {
                    istringstream iss(line);
                    string empty;
                    iss >> empty;

                    int count, from, to;
                    iss >> count >> empty;
                    iss >> from >> empty;
                    iss >> to;
                    move(count, from, to);
                } else {
                    int whitespace = 0;
                    int column = 0;

                    for (int i = 0; i < line.size(); i++) {
                        char c = line[i];
                        if (c == ' ') {
                            whitespace++;
                        } else if (c == '[') {
                            column += ((whitespace-1)/3)+1;
                            whitespace = 0;
                        } else if (isalpha(c)) {
                            Columns[column].push_back(c);
                            lengh[column]++;
                        }
                    }
                }


            }
        }
        //cout << "woo";

        for (int c = 0; c < max_c; c++) {
            //cout << lengh[c];

            if (lengh[c] >= 1) cout << Columns[c][0];
        }
        //deque<char> CCC[max_c] = (*Columns);
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}