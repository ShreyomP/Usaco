// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("feast.in");
    ofstream out("feast.out");
	int t,a,b;
    in>>t>>a>>b;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<int> visited(t,0);
    int most=0;
    while (!q.empty()) {
        int full=q.front().first;
        int drank=q.front().second;
        q.pop();
        most=max(most,full);
        if (full+a<=t && visited[full+a]==0) {
            visited[full+a]=1;
            q.push({full+a,drank});
        }
        if (full+b<=t && visited[full+b]==0) {
            visited[full+b]=1;
            q.push({full+b,drank});
        }
        if (visited[floor(full/2)]==0 && drank==0) {
            drank=1;
            visited[floor(full/2)]=1;
            q.push({floor(full/2),drank});
        }
    }
    out<<most;
}
