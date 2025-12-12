#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;

int main() {
    fstream file;
    file.open("../input.txt", ios::in);
    string line;
    vector<string> shapes;
    while (getline(file, line) && line.find('x') == string::npos) {
        if (isdigit(line[0])) {
            string shape;
            while (getline(file, line) && !line.empty()) {
                shape += line;
            }
            shapes.push_back(move(shape));
        }
    }

    vector<pair<pair<ll, ll>, vector<ll>>> grid_info;
    do {
        size_t idx = line.find(':');
        string grid_size_str = line.substr(0, idx);
        string quantity_str = line.substr(idx + 2);

        stringstream ss(grid_size_str);
        ll x, y;
        char _; 
        ss >> x >> _ >> y;
        stringstream ss1(quantity_str);
        vector<ll> temp_array;
        string temp;
        while (ss1 >> temp) {
            temp_array.push_back(stoll(temp));
        }
        grid_info.push_back({{x, y}, move(temp_array)});
    } while(getline(file, line));

    vector<ll> number_of_hash_in_shape;
    for(string &shape: shapes) {
        ll count = 0;
        for(char &ch: shape) {
            if(ch == '#') count++;
        }
        number_of_hash_in_shape.push_back(count);
    }

    ll ans = 0;
    for(auto &[size_info, count_arr]: grid_info) {
        ll cols = size_info.first;
        ll rows = size_info.second;

        ll area_to_be = 0;
        for(int i=0;i<count_arr.size(); i++) {
            area_to_be += count_arr[i] * number_of_hash_in_shape[i];
        }
        ll area_available = rows * cols;
        if(area_available >= area_to_be) ans++;
    }
    cout<<ans;
}