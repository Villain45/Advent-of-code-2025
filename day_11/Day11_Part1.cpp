#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;

ll ans = 0;

void dfs(unordered_map<string, vector<string>> &graph, string current, string end, unordered_map<string, bool> &visited) {
    if(current == end) {
        ans++;
        return;
    }
    visited[current] = true;
    for(string &output: graph[current]) {
        if(!visited[output]) {
            dfs(graph, output, end, visited);
        }
    }
    visited[current] = false;
}

int main() {
    fstream file;
    file.open("../input.txt", ios::in);
    string line;
    unordered_map<string, vector<string>> graph;
    while(getline(file, line)) {
        size_t idx = line.find(':');
        string device = line.substr(0, idx);
        string output_str = line.substr(idx+2);
        stringstream ss(output_str);
        string output;
        while(ss>>output) {
            graph[device].push_back(output);
        }
    }
    string start = "you";
    string end = "out";
    unordered_map<string, bool> visited;
    dfs(graph, start, end, visited);
    cout<<ans;
}