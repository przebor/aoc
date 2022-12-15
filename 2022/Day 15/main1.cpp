#include<bits/stdc++.h>
using namespace std;

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else
const bool DEBUG_MODE = true;
#endif


int CheckY = 2000000;
int Total = 0;

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

void magic() {
    vector<pair<int, int>> Ranges;
    set<int> Beacon_x;
    for (pair<int, int> p : Beacons) {
        if (CheckY == p.second) Beacon_x.insert(p.first);
    }
    for (Sensor s : Sensors) {
        int a = s.pos.first-s.b_dist+abs(s.pos.second-CheckY);
        int b = s.pos.first+s.b_dist-abs(s.pos.second-CheckY);
        if (a <= b) Ranges.push_back({a, b});
    }
    sort(Ranges.begin(), Ranges.end());

    int prev_end = Ranges[0].first;
    for (int i = 0; i < Ranges.size(); i++) {
        if (prev_end > Ranges[i].second) continue;
        Total += Ranges[i].second-prev_end;
        for (int x : Beacon_x) {
            if (prev_end < x && x <= Ranges[i].second) {
                Total--;
            }
        }
        prev_end = Ranges[i].second;
    }

    if (Ranges.size() > 0) Total++;
}

int main(int argc, char** argv) {
    if (argc > 1 || DEBUG_MODE) {
        // Sketchy parsing
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

        magic();
        cout << Total;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}