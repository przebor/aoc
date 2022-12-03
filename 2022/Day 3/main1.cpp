#include<bits/stdc++.h>
using namespace std;

int Total = 0;

inline int char_to_priority(char c) {
    if (isupper(c)) {
        return c - 'A' + 27;
    } else {
        return c - 'a' + 1;
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
                set<char> woo;
                istringstream iss(line);
                string s; iss >> s;

                for (int i = 0; i < s.size(); i++) {
                    if (i >= s.size()/2) {
                        if (woo.count(s[i]) == 1) {
                            Total += char_to_priority(s[i]);
                            woo.erase(s[i]);
                        }
                    } else {
                        woo.insert(s[i]);
                    }
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