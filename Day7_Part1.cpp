#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_valid_point(pair<int,int> beam, int n, int m) {
    return beam.first>=0 && beam.first< n && beam.second>=0 && beam.second< m;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<vector<char>> mat;
    bool start_found = false;
    size_t start_index = -1;
    while(getline(file, line)) {
        if(!start_found) {
            start_index = line.find('S');
            if(start_index != string::npos) {
                start_found = true;
            }
        }
        vector<char> temp(line.begin(), line.end());
        mat.push_back(temp);
    }
    int count = 0;
    int n = mat.size(), m = mat[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        if(mat[i][start_index] == '^') {
            q.push({i, start_index});
            break;
        }
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    while(!q.empty()) {
        auto beam = q.front();
        q.pop();
        if(is_valid_point(beam, n, m) && !visited[beam.first][beam.second]) {
            visited[beam.first][beam.second] = 1;
            if(mat[beam.first][beam.second] == '^') {
                count++;
                q.push({beam.first+1, beam.second-1});
                q.push({beam.first+1, beam.second+1});
            } else {
                q.push({beam.first+1, beam.second});
            }
        }
    }
    cout<<count;
}