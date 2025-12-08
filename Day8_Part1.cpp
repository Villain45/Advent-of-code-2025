#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;

vector<int> parent;
vector<int> size_of_node;
int junctions = 1000;

ll get_euclid_distance(tup p, tup q) { 
    return pow((get<0>(p)-get<0>(q)), 2) + pow((get<1>(p)-get<1>(q)), 2) + pow((get<2>(p)-get<2>(q)), 2); 
}

int find_parent(int node) {
    while(parent[node] != node) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}

void make_junction(int node1, int node2) {
    int node1_parent = find_parent(node1); 
    int node2_parent = find_parent(node2); 
    if(node1_parent != node2_parent) { 
        if(size_of_node[node1_parent] < size_of_node[node2_parent]) {
            swap(node1_parent, node2_parent); 
        }
        parent[node2_parent] = node1_parent;
        size_of_node[node1_parent] += size_of_node[node2_parent];
    }
}

int main() {
    fstream file;
    file.open("input.txt", ios::in);
    string line;
    vector<tup> points;
    while(getline(file, line)) {
        int x,y,z;
        char _;
        stringstream ss(line);
        ss>>x>>_>>y>>_>>z;
        points.push_back(make_tuple(x,y,z));
    }
    int n=points.size();
    vector<tup> edges;
    for(int i=0;i<n;i++) {
        auto p = points[i]; 
        for(int j=0;j<n && i!=j;j++) {
            auto q = points[j];
            ll dist = get_euclid_distance(p, q);
            edges.push_back(make_tuple(dist, i, j));
        }
    }
    sort(edges.begin(), edges.end());

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);

    size_of_node.assign(n, 1);

    for(int i=0;i<junctions;i++) {
        make_junction(get<1>(edges[i]), get<2>(edges[i]));
    }

    sort(size_of_node.begin(), size_of_node.end(), greater<int>());
    cout<<size_of_node[0] * size_of_node[1] * size_of_node[2];
}