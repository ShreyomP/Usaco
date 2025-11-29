// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("revegetate.in");
    ofstream out("revegetate.out");
	int n,m;
    in>>n>>m;
    vector<vector<int>> adj(n);
    for (int x=0; x<m; x++) {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }
    vector<int> types(n,-1);
    for (int x=0; x<n; x++) {
        for (int type=1; type<=4; type++) {
            bool ok=true;
            for (auto it : adj[x]) {
                if (types[it]==type) {
                    ok=false;
                    break;
                }
            }
            if (ok==false) {
                continue;
            }
            else {
                types[x]=type;
                break;
            }
        }
    }
    for (int x=0; x<n; x++) {
        out<<types[x];
    }
}
