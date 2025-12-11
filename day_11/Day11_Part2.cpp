#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<string,bool,bool> tup;

map<tup, ll> memo;

ll dfs(unordered_map<string, vector<string>> &graph, string current, string end, unordered_map<string, bool> &visited, bool has_fft, bool has_dac) {
    if(current == end) {
        return has_fft && has_dac;
    }
    tup find_key = {current, has_fft, has_dac};
    if(memo.find(find_key) != memo.end())
        return memo[find_key];
    
    ll temp_ans = 0;

    visited[current] = true;
    for(string &output: graph[current]) {
        if(!visited[output]) {
            temp_ans += dfs(graph, output, end, visited, has_fft || output == "fft", has_dac || output == "dac");
        }
    }
    visited[current] = false;
    return memo[find_key] = temp_ans;
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
    string start = "svr";
    string end = "out";
    unordered_map<string, bool> visited;

    cout<<dfs(graph, start, end, visited, false, false);
}