#include<bits/stdc++.h>
using namespace std;
vector<string> process_input(string &line) {
    stringstream ss(line);
    string temp;
    vector<string> ranges;
    while(getline(ss, temp, ',')) {
        ranges.push_back(temp);
    }
    return ranges;
}

vector<string> split_num(string &num, int chunk) {
    vector<string> ans;
    int cur_pos = 0;
    while(cur_pos < num.size()) {
        ans.push_back(num.substr(cur_pos, chunk));
        cur_pos+=chunk;
    }
    return ans;
}

bool is_valid_id(long long &num, int size) {
    if(size % 2 == 0) {
        long long divisior = pow(10, size/2);
        if(num / divisior == num % divisior) return true;
    }
    // brute
    string num_str = to_string(num);
    for(int i=1;i<=size/2;i++) {
        vector<string> num_parts = split_num(num_str, i);
        set<string> s(num_parts.begin(), num_parts.end());
        if(s.size() == 1) return true;
    }
    return false;

    // Optimized
    // string num_str_double = to_string(num) + to_string(num);
    // string modified_num_str = num_str_double.substr(1, num_str_double.size() - 2);
    // return modified_num_str.find(to_string(num)) != string::npos;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<string> ranges;
    long long ans = 0;
    while(getline(file, line)) {
        ranges = process_input(line);
        for(string range: ranges) {
            size_t pos = range.find('-');
            long long first_id = stoll(range.substr(0, pos)), last_id = stoll(range.substr(pos+1));
            for(long long i = first_id; i <= last_id; i++) {
                int size = (i == 0) ? 1 : log10(i) + 1;
                ans += is_valid_id(i, size) ? i : 0;
            }
        }
    }
    cout<<ans;
}