#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> process_input(string line) {
    stringstream ss(line);
    string temp;
    vector<int> inputs;
    while(ss >> temp) {
        inputs.push_back(stoi(temp));
    }
    return inputs;
}

ll get_ans(vector<vector<int>> &nums, char op, int col) {
    ll temp_ans;
    if(op == '+') {
        temp_ans = 0;
        for(int i=0;i<nums.size();i++) {
            temp_ans += nums[i][col];
        }
    } else if(op == '*') {
        temp_ans = 1;
        for(int i=0;i<nums.size();i++) {
            temp_ans *= nums[i][col];
        }
    } else {
        cout<<"Who are you?"<<endl;
        temp_ans = 0;
    }
    return temp_ans;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<vector<int>> nums;
    vector<char> operators;
    while(getline(file, line)) {
        if(line[0] != '+' && line[0] != '*') {
            vector<int> temp = process_input(line);
            nums.push_back(temp);
        } else {
            char op;
            stringstream ss(line);
            while(ss >> op) {
                operators.push_back(op);
            }
        }
    }
    int n = nums[0].size();
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans += get_ans(nums, operators[i], i);
    }
    cout<<ans;
}