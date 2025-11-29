// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};

int main() {
    ifstream in("countcross.in");
    ofstream out("countcross.out");
	int n,k,r;
    in>>n>>k>>r;
    //vector<vector<int>> grid(n,vector<int>(n));
    set<pair<pair<int,int>,pair<int,int>>> road;
    for (int x=0; x<r; x++) {
        pair<int,int> a,b;
        in>>a.first>>a.second>>b.first>>b.second;
        a.first--;
        a.second--;
        b.first--;
        b.second--;
        road.insert({{a.first,a.second},{b.first,b.second}});
    }
    set<pair<int,int>> cows;
    for (int x=0; x<k; x++) {
        int cx,cy;
        in>>cx>>cy;
        cx--;
        cy--;
        cows.insert({cx,cy});
    }
    int total=0;
    for (auto it : cows) {
        set<pair<int,int>> visited;
        int reachable=0;
        queue<pair<int,int>> q;
        q.push({it.first,it.second});
        visited.insert({it.first,it.second});
        while (!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if (cows.count({x,y})) {
                reachable++;
            }
            for (auto its : directions) {
                int newx=x+its.first;
                int newy=y+its.second;
                if ((newx>=0 && newx<n) && (newy>=0 && newy<n)) {
                    if (!road.count({{newx,newy},{x,y}}) && !road.count({{x,y},{newx,newy}})) {
                        if (!visited.count({newx,newy})) {
                            visited.insert({newx,newy});
                            q.push({newx,newy});
                        }
                    }
                }
            }
        }
        int diff=k-reachable;
        total+=diff;
    }
    out<<total/2;
}
