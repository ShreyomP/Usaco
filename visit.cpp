// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;



void floodfill(int a, vector<int> &visited, const vector<vector<int>> &adj, vector<int> &component, int count) {
    if (visited[a]) {
        return;
    }
    visited[a] = 1;
    component[a] = count;
    for (int it : adj[a]) {
        if (!visited[it]) {
            floodfill(it, visited, adj, component, count);
        }
    }
}

int main() {
    ifstream in("milkvisits.in");
    ofstream out("milkvisits.out");
	int n,m;
    in>>n>>m;
    vector<char> cows(n);
    for (int x=0; x<n; x++) {
        in>>cows[x];
    }
    vector<vector<int>> adj(n);
    for (int x=1; x<n; x++) {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        if (cows[a]==cows[b]) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    vector<int> visited(adj.size());
    vector<int> component(n);
    int count=1;
    for (int x=0; x<n; x++) {
        if (visited[x]==0) {
            component[x]=count;
            floodfill(x,visited,adj,component,count);
            count++;
        }
    }
    for (int x=0; x<m; x++) {
        int a,b;
        char color;
        in>>a>>b>>color;
        a--;
        b--;
        if (component[a]==component[b] && cows[a]==color) {
            out<<1;
        }
        else if (component[a]==component[b]) {
            out<<0;
        }
        else {
            out<<1;
        }
    }
}
