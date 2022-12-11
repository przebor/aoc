#include<bits/stdc++.h>
using namespace std;

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else
const bool DEBUG_MODE = true;
#endif

enum Op {
    Addition,
    Multiplication,
    Square
};

struct Operation {
    Op operation;
    int second_item;
};

struct Test {
    int div_check = 1;
    int if_true;
    int if_false;
};

struct Monkey {
    vector<int> items;
    Operation operation;
    Test test;
    int inspected_items = 0;
};

vector<Monkey> Monkeys;

// The stuff that does stuff as described in stuff
inline void stuff() {
    for (int r = 0; r < 20; r++) {
        for (int m_i = 0; m_i < Monkeys.size(); m_i++) {
            int m_i_n = Monkeys[m_i].items.size();
            set<int, greater<int>> to_remove;
            for (int m_i_i = 0; m_i_i < m_i_n; m_i_i++) {
                Monkeys[m_i].inspected_items++;
                if (Monkeys[m_i].operation.operation == Op::Addition) {
                    Monkeys[m_i].items[m_i_i] += Monkeys[m_i].operation.second_item;
                } else if (Monkeys[m_i].operation.operation == Op::Multiplication) {
                    Monkeys[m_i].items[m_i_i] *= Monkeys[m_i].operation.second_item;
                } else {
                    Monkeys[m_i].items[m_i_i] = Monkeys[m_i].items[m_i_i] * Monkeys[m_i].items[m_i_i];
                }

                Monkeys[m_i].items[m_i_i] /= 3;

                if (Monkeys[m_i].items[m_i_i] % Monkeys[m_i].test.div_check == 0) {
                    Monkeys[Monkeys[m_i].test.if_true].items.push_back(Monkeys[m_i].items[m_i_i]);
                } else {
                    Monkeys[Monkeys[m_i].test.if_false].items.push_back(Monkeys[m_i].items[m_i_i]);
                }
                to_remove.insert(m_i_i);
            }
            for (int i : to_remove) {
                Monkeys[m_i].items.erase(Monkeys[m_i].items.begin() + i);
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1 || DEBUG_MODE) {
        // Sketchy parsing
        ifstream input_file((DEBUG_MODE ? "sample1.in" : argv[1]));
        string line;
        string unknown;
        int cur_monkey_id;

        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                if (line[0] == 'M') {
                    cur_monkey_id = line[7] - '0';
                    Monkeys.push_back({});
                } else if (line[2] == 'S') {
                    string nums_s = line.substr(18, line.size()-18);
                    string cur_num = "";
                    vector<int> nums_i;

                    for (char c : nums_s) {
                        if (c == ' ') continue;
                        if (c == ',') {
                            nums_i.push_back(stoi(cur_num));
                            cur_num = "";
                            continue;
                        }
                        cur_num += c;
                    }
                    nums_i.push_back(stoi(cur_num));

                    Monkeys[cur_monkey_id].items = nums_i;
                } else if (line[2] == 'O') {
                    if (line[23] == '+') {
                        Monkeys[cur_monkey_id].operation.operation = Op::Addition;
                        Monkeys[cur_monkey_id].operation.second_item = stoi(line.substr(25, line.size()-25));
                    } else {
                        Monkeys[cur_monkey_id].operation.operation = Op::Multiplication;
                        string second = line.substr(25, line.size()-25);
                        if (second == "old") {
                            Monkeys[cur_monkey_id].operation.operation = Op::Square;
                        } else {
                            Monkeys[cur_monkey_id].operation.second_item = stoi(second);
                        }
                    }
                } else if (line[2] == 'T') {
                    Monkeys[cur_monkey_id].test.div_check = stoi(line.substr(21, line.size()-21));
                } else if (line[4] == 'I') {
                    if (line[7] == 't') {
                        Monkeys[cur_monkey_id].test.if_true = line[29] - '0';
                    } else {
                        Monkeys[cur_monkey_id].test.if_false = line[30] - '0';
                    }
                }
            }
        }

        stuff();
        multiset<int, greater<int>> inspected_items_count;
        for (Monkey m : Monkeys) {
            inspected_items_count.insert(m.inspected_items);
        }
        auto second_iterator = inspected_items_count.begin();
        advance(second_iterator, 1);
        cout << *inspected_items_count.begin() * *second_iterator << endl;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}