#include<bits/stdc++.h>
using namespace std;

vector<pair<string, int>> Digits = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

int main() {
    ifstream infile("input2.in");
    long long res = 0;
    string s;

    while (infile >> s) {
        vector<int> nums;

        for (int i = 0; i < s.size(); i++) {
            int n = s[i] - '0';
            if (n >= 0 && n <= 9) {
                nums.push_back(n);
            } else {
                // Could be optimised but, whatever, it's just AoC
                for (pair<string, int> digit : Digits) {
                    if (i >= digit.first.size()-1) {
                        string compare_a = s.substr(i-digit.first.size()+1, digit.first.size());
                        if (compare_a == digit.first) {
                            nums.push_back(digit.second);
                        }
                    }
                }
            }
        }
        res += (*(nums.end()-1))+(*nums.begin())*10;
    }
    cout << res << endl;
}

