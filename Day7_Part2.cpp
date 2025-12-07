#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp;

bool is_valid_point(vector<vector<char>> &mat, int i, int j) {
    return i>=0 && i < mat.size() && j>=0 && j < mat[0].size();
}

ll dfs(vector<vector<char>> &mat, int i, int j) {
    if(i == mat.size() - 1) {
        return 1;
    }

    ll dimensions=0;
    if(dp[i][j] != -1) return dp[i][j]; 

    if(mat[i][j] == '^') {
        if(is_valid_point(mat, i, j)) dimensions+=dfs(mat, i+1, j-1);
        if(is_valid_point(mat, i, j)) dimensions+=dfs(mat, i+1, j+1);
    } else {
        if(is_valid_point(mat, i, j)) dimensions+=dfs(mat, i+1, j);
    }
    return dp[i][j] = dimensions;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<vector<char>> mat;
    bool start_found = false;
    size_t start_index_j = -1;
    while(getline(file, line)) {
        if(!start_found) {
            start_index_j = line.find('S');
            if(start_index_j != string::npos) {
                start_found = true;
            }
        }
        vector<char> temp(line.begin(), line.end());
        mat.push_back(temp);
    }
    int start_index_i = -1;
    int n = mat.size(), m = mat[0].size();
    for(int i=0;i<n;i++) {
        if(mat[i][start_index_j] == '^') {
            start_index_i = i;
            break;
        }
    }
    dp.assign(n, vector<ll>(m, -1));
    cout<<dfs(mat, start_index_i, start_index_j);;
}