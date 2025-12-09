#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
typedef pair<ll,ll> pll;

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<pair<ll,ll>> points;

    while(getline(file, line)) {
        ll x,y;
        char _;
        stringstream ss(line);
        ss>>x>>_>>y;
        points.push_back({x,y});
    }

    int n = points.size();
    vector<pair<pll,pll>> edges;
    for (int i = 0; i < n - 1; i++) {
        edges.push_back({{points[i].first, points[i].second}, {points[i+1].first, points[i+1].second}});
    }
    edges.push_back({{points[n-1].first, points[n-1].second}, {points[0].first, points[0].second}});

    ll ans = LLONG_MIN;
    for(int i=0;i<points.size();i++) {
        auto point1 = points[i];
        for(int j=0;j<points.size();j++) {
            if(i==j) continue;
            auto point2 = points[j];
            ll minX = min(point1.first, point2.first);
            ll minY = min(point1.second, point2.second);
            ll maxX = max(point1.first, point2.first);
            ll maxY = max(point1.second, point2.second);
            ll area = (maxX- minX + 1) * (maxY - minY + 1);
            bool is_valid_rectangle = true;
            for(auto &edge: edges) {
                pll v1 = edge.first;
                pll v2 = edge.second;
                ll minEdgeX = min(v1.first, v2.first); 
                ll minEdgeY = min(v1.second, v2.second);
                ll maxEdgeX = max(v1.first, v2.first);
                ll maxEdgeY = max(v1.second, v2.second);
                if (minX < maxEdgeX && minY < maxEdgeY && maxX > minEdgeX && maxY > minEdgeY) {
                    // false, when any edge is moving through the rectangle
                    is_valid_rectangle = false;
                    break;
                }
            }
            // true, when all the edges are on border of rectangle
            if(is_valid_rectangle) {
                ans=max(ans, area);
            }
        }
    }
    cout<<ans;
}