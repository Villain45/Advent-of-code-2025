#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<pair<int,int>> points;
    while(getline(file, line)) {
        int x,y;
        char _;
        stringstream ss(line);
        ss>>x>>_>>y;
        points.push_back({x,y});
    }
    ll ans = LLONG_MIN;
    for(int i=0;i<points.size();i++) {
        auto point1 = points[i];
        for(int j=0;j<points.size();j++) {
            if(i==j) continue;
            auto point2 = points[j];
            ll diff1 = abs(point1.first - point2.first);
            ll diff2 = abs(point1.second - point2.second);
            if(diff1 != diff2) {
                ll area = (diff1 + 1) * (diff2 + 1);
                ans = max(ans, area);
            }
        }
    }
    cout<<ans;
}