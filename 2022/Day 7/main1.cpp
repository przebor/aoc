#include<bits/stdc++.h>
using namespace std;

struct File {
    string name;
    long long sizee;
};

struct Directory {
    string path;
    vector<File> files;
    vector<string> dirs;
};

struct Graph {
    map<string, Directory> directories;
};

Graph g;
long long Total = 0;

long long get_size(string path) {
    long long cnt = 0;
    for (string subdir : g.directories[path].dirs) {
        cnt += get_size(subdir);
    }
    for (File f : g.directories[path].files) {
        cnt += f.sizee;
    }

    if (cnt <= 1e5) Total += cnt;

    return cnt;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        ifstream input_file(argv[1]);

        string line;
        string dir = "";
        while (getline(input_file, line)) {
            if (line.empty()) {
                continue;
            } else {
                if (line[0] == '$') {
                    // Is a command
                    if (line[2] == 'c') {
                        string subpath = line.substr(5, line.size()-5);
                        if (subpath == "/") dir = "/";
                        else if (subpath == "..") {
                            int pos = dir.find_last_of('/');
                            dir = dir.substr(0, pos);
                        } else if (dir == "/") {
                            dir += subpath;
                        } else {
                            dir += "/"+subpath;
                        }
                        g.directories[dir].path = dir;
                    }
                } else {
                    if (line[0] == 'd') {
                        string subdir = dir + (dir == "/" ? "" : "/") + line.substr(4, line.size()-1);
                        g.directories[subdir].path = subdir;
                        g.directories[dir].dirs.push_back(subdir);
                    } else {
                        int space_pos = line.find_first_of(' ');
                        long long size = stol(line.substr(0, space_pos));
                        string name = dir+(dir == "/" ? "" : "/")+line.substr(space_pos+1, line.size()-space_pos);
                        g.directories[dir].files.push_back({name, size});
                    }
                }
            }
        }
        get_size("/");
        cout << Total << endl;

        return 0;
    } else {
        cerr << "No input file specified" << endl;
        return 1;
    }
}