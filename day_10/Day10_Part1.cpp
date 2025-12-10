#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;

int minimal_clicks(vector<bool> &final_indicators, vector<vector<int>> &button_array) {
    vector<bool> initial_stage(final_indicators.size(), false);
    queue<pair<vector<bool>,int>> q;
    
    q.push({initial_stage, 0});
    set<vector<bool>> visited;

    while(!q.empty()) {
        auto [curr_stage, clicks] = q.front();
        q.pop();
        if(curr_stage == final_indicators) {
            return clicks;
        }
        for(auto &buttons: button_array) {
            vector<bool> next_stage = curr_stage;
            for(int &button: buttons) {
                next_stage[button] = !next_stage[button];
            }
            if(visited.find(next_stage) == visited.end()) {
                visited.insert(next_stage);
                q.push({next_stage, clicks + 1});
            }
        }
    }
    return -1;
}

int main() {
    fstream file;
    file.open("/input.txt", ios::in);
    string line;
    vector<vector<int>> buttons;
    vector<bool> indicators;
    vector<int> joltage;
    int ans = 0;
    while(getline(file, line)) {
        indicators.clear();
        buttons.clear();
        joltage.clear();
        size_t l = line.find('[');
        size_t r = line.find(']');
        for(int i=l+1;i<r;i++) {
            indicators.push_back(line[i] == '#');
        }
        for(int i=0;i<line.size();i++) {
            if(line[i] == '(') {
                vector<int> temp;
                int num = 0;
                bool numUpdated = false;
                i++;
                while (i < line.size() && line[i] != ')') {
                    if (isdigit(line[i])) {
                        num = num * 10 + (line[i] - '0');
                        numUpdated = true;
                    } else if (line[i] == ',') {
                        if (numUpdated) {
                            temp.push_back(num);
                        }
                        num = 0;
                        numUpdated = false;
                    }
                    i++;
                }
                if (numUpdated) temp.push_back(num);
                buttons.push_back(temp);
            }
        }
        l = line.find('{');
        r = line.find('}');
        string jolts = line.substr(l + 1, r - l - 1);
        stringstream ss(jolts);
        string num;
        while (getline(ss, num, ',')) {
            joltage.push_back(stoi(num));
        }
        ans += minimal_clicks(indicators, buttons);
    }
    cout<<ans;
}