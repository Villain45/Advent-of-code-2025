#include<bits/stdc++.h>
using namespace std;
int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    int ans = 0;
    while(getline(file, line)) {
        pair<char,int> max_number = {'\0', -1};
        pair<char,int> possible_num1 = {'\0', -1}, possible_num2 = {'\0', -1};
        int temp_var = INT_MIN;
        
        for(int i=0;i<line.size();i++) {
            if(line[i] > temp_var) {
                temp_var = line[i];
                max_number = {line[i], i};
            }
        }

        temp_var = INT_MIN;
        for(int i=0;i<max_number.second;i++) {
            if(line[i] > temp_var) {
                temp_var = line[i];
                possible_num1 = {line[i], i};
            }
        }

        temp_var = INT_MIN;
        for(int i=max_number.second + 1;i<line.size();i++) {
            if(line[i] > temp_var) {
                temp_var = line[i];
                possible_num2 = {line[i], i};
            }
        }
        int num;
        if(possible_num1.second == -1 && possible_num2.second != -1) {
            num = (max_number.first - '0') * 10 + possible_num2.first - '0';
        } else if(possible_num1.second != -1 && possible_num2.second == -1) {
            num = (possible_num1.first - '0') * 10 + max_number.first - '0';
        } else {
            num = max((max_number.first - '0') * 10 + possible_num2.first - '0', (possible_num2.first - '0') * 10 + max_number.first - '0');
        }
        ans+=num;
    }
    cout<<ans;
}