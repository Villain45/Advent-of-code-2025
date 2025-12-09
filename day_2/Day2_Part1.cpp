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

bool is_valid_id(long long &num, int split_size) {
    long long divisior = pow(10, split_size);
    return num / divisior == num % divisior;
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
                int num_size = (i == 0) ? 1 : log10(i) + 1;
                if(num_size % 2 == 1) continue;
                ans += is_valid_id(i, num_size/2) ? i : 0;
            }
        }
    }
    cout<<ans;
}