#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_fresh(vector<pair<ll,ll>> &ranges, ll ingredient_id) {
    for(auto range: ranges) {
        if(range.first <= ingredient_id && ingredient_id <= range.second) {
            return true;
        }
    }
    return false;
}

vector<pair<ll,ll>> merge_ranges(vector<pair<ll,ll>> ranges) {
    vector<pair<ll,ll>> new_ranges;
    new_ranges.push_back(ranges[0]);
    int cnt = 0;
    for(int i=1;i<ranges.size();i++) {
        if(ranges[i].first <= new_ranges[cnt].second) {
            new_ranges[cnt].second = max(new_ranges[cnt].second, ranges[i].second);
        } else {
            new_ranges.push_back(ranges[i]);
            cnt++;
        }
    }
    return new_ranges;
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<pair<ll,ll>> ranges;
    while(getline(file, line) && line!="") {
        size_t pos = line.find('-');
        ll l_bound = stoll(line.substr(0, pos));
        ll u_bound = stoll(line.substr(pos+1));
        ranges.push_back({l_bound, u_bound});
    }
    sort(ranges.begin(), ranges.end());
    ranges = merge_ranges(ranges);
    int fresh_ids=0;
    while(getline(file, line)) {
        ll ingredient_id = stoll(line);
        fresh_ids+=is_fresh(ranges, ingredient_id);
    }
    cout<<fresh_ids;
}