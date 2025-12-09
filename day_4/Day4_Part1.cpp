#include<bits/stdc++.h>
using namespace std;
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool is_valid_cell(int n, int m, int i, int j) {
    return i>=0 && j>=0 && i<n && j<m;
}

bool is_valid_roll(vector<vector<char>> &mat, int n, int m, int row,int col) {
    int neighbor_rolls=0;
    for(int i=0;i<8;i++) {
        int n_row = row + dr[i];
        int n_col = col + dc[i];
        if(is_valid_cell(n, m, n_row, n_col) && mat[n_row][n_col] == '@') {
            neighbor_rolls++;
        }
    }
    return neighbor_rolls < 4;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    int ans = 0;
    vector<vector<char>> mat;
    while(getline(file, line)) {
        vector<char> temp(line.begin(), line.end());
        mat.push_back(temp);
    }
    int count=0;
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j] == '@') {
                count += is_valid_roll(mat, n, m, i ,j);
            }
        }
    }
    cout<<count;
}