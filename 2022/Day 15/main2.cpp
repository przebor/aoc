#include<bits/stdc++.h>
using namespace std;

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else
const bool DEBUG_MODE = true;
#endif

const int max_y = 4000000;

struct Sensor {
    pair<int, int> pos;
    int b_dist;
};

enum InputReadingStatus {
    SensorX,
    SensorY,
    BeaconX,
    BeaconY
};

inline int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
} 

vector<Sensor> Sensors;
vector<pair<int, int>> Beacons;
pair<int, int> Result;

void magic(int y) {
    vector<pair<int, int>> RRanges;
    vector<pair<int, int>> Ranges;
    set<int> Beacon_x;
    for (pair<int, int> p : Beacons) {
        if (y == p.second) Beacon_x.insert(p.first);
    }

    for (Sensor s : Sensors) {
        int a = s.pos.first-s.b_dist+abs(s.pos.second-y);
        int b = s.pos.first+s.b_dist-abs(s.pos.second-y);
        if (a <= b) {
            RRanges.push_back({a, b});
        }
    }
    sort(RRanges.begin(), RRanges.end());
    
    int last_end = -1e9;
    for (int i = 0; i < RRanges.size(); i++) {
        int a = max(last_end, RRanges[i].first);
        int b = RRanges[i].second;
        if (a <= b) {
            Ranges.push_back({a, b});
            last_end = b;
        }
    }

    for (int i = 0; i < Ranges.size(); i++) {
        if (i == Ranges.size()-1) {
            if (Ranges[i].second < max_y) {
                Result = {Ranges[i].second+1, y};
            }
        } else if (Ranges[i].second+1 < Ranges[i+1].first) {
            Result = {Ranges[i].second+1, y};
        }
    }
}

int main(int argc, char** argv) {
    if (argc > 1 || DEBUG_MODE) {
        ifstream input_file((DEBUG_MODE ? "sample1.in" : argv[1]));
        string line;

        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                pair<int, int> Senso;
                pair<int, int> Beacon;
                //                 \/ the funny
                InputReadingStatus irs = InputReadingStatus::SensorX;
                string num_s = "";
                line += " ";
                for (char c : line) {
                    if (isdigit(c) || c == '-') {
                        num_s += c;
                    } else if (num_s != "") {
                        int num = stoi(num_s);
                        num_s = "";

                        if (irs == InputReadingStatus::SensorX) {
                            irs = InputReadingStatus::SensorY;
                            Senso.first = num;
                        } else if (irs == InputReadingStatus::SensorY) {
                            irs = InputReadingStatus::BeaconX;
                            Senso.second = num;
                        } else if (irs == InputReadingStatus::BeaconX) {
                            irs = InputReadingStatus::BeaconY;
                            Beacon.first = num;
                        } else if (irs == InputReadingStatus::BeaconY) {
                            Beacon.second = num;
                        }
                    }
                }

                Sensors.push_back(Sensor {Senso, dist(Senso, Beacon)});
                Beacons.push_back(Beacon);
            }
        }

        for (int y = 0; y <= max_y; y++) magic(y);
        cout << (long long)Result.first*4000000+(long long)Result.second << endl;;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}