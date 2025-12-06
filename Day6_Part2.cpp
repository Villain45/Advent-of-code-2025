#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isGap(vector<char> line) {
    for(auto ele: line) {
        if(ele != ' ') return false;
    }
    return true;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<vector<char>> mat;
    while(getline(file, line)) {
        vector<char> temp(line.begin(), line.end());
        mat.push_back(temp);
    }
    char op;
    ll ans = 0;
    ll temp_ans = -1;
    for(int i=0;i<mat[0].size();i++) {
        int num = 0;
        vector<char> each_line;
        for(int j=0;j<mat.size();j++) {
            if(isdigit(mat[j][i])) {
                num = num * 10 + mat[j][i] - '0';
            } else if(mat[j][i] == '+' || mat[j][i] == '*') {
                op = mat[j][i];
            }
            each_line.push_back(mat[j][i]);
        }
        if(op == '+' && num != 0) {
            temp_ans = temp_ans == -1 ? 0 : temp_ans;
            temp_ans += num;
        } else if(op == '*' && num != 0) {
            temp_ans = temp_ans == -1 ? 1 : temp_ans;
            temp_ans *= num;
        }
        if(isGap(each_line) || i == mat[0].size() - 1) {
            ans += temp_ans;
            temp_ans = -1;
        }
    }
    cout<<ans;
}                                  