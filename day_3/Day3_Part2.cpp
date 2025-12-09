#include<bits/stdc++.h>
using namespace std;

int batteries_required = 12;

long long get_max_jolt(string line) {
    int first_index = 0, last_index = 0;
    size_t len = line.size();
    long long max_jolt = 0;
    for(int i=1;i<=batteries_required;i++) {
        last_index = len - batteries_required + i;
        string current_digits = line.substr(first_index, last_index - first_index);
        char max_digit_in_window = *max_element(current_digits.begin(), current_digits.end());
        size_t max_digit_index = line.find(max_digit_in_window, first_index);
        first_index = max_digit_index + 1;
        max_jolt = max_jolt * 10 + (max_digit_in_window - '0');
    }
    return max_jolt;
}
int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    long long ans = 0;
    while(getline(file, line)) {
        long long max_jolt = get_max_jolt(line);
        ans+=max_jolt;
    }
    cout<<ans;
}