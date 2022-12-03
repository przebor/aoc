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
        map<char, int> Counter;
        int i = 0;
        while (getline(input_file, line)) {
            if (i >= 3) {
                Counter.clear();
                i = 0;
            }
            if (line.empty()) {
                Counter.clear();
                i = 0;
                continue;
            } else {
                set<char> woo;
                istringstream iss(line);
                string s; iss >> s;

                for (int i = 0; i < s.size(); i++) {
                    if (woo.count(s[i]) == 0) {
                        if (Counter.count(s[i]) == 0) Counter[s[i]] = 1;
                        else Counter[s[i]]++;

                        if (Counter[s[i]] == 3) Total += char_to_priority(s[i]);
                    }
                    woo.insert(s[i]);
                }
                i++;
            }
        }

        cout << Total << endl;
        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}