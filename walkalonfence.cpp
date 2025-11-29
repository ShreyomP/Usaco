// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,p;
    cin>>n>>p;
    vector<vector<int>> grid(1005,vector<int>(1005));
    pair<int,int> loc;
    vector<pair<int,int>> posts(p);
    for (int x=0; x<p; x++) {
        cin>>posts[x].first>>posts[x].second;
    }
    loc=posts[0];
    grid[loc.first][loc.second]=1;
    int steps=2;
    for (int x=1; x<p; x++) {
        if (loc.first==posts[x].first) {
            int dir=1;
            if (posts[x].second-loc.second<0) {
                dir=-1;
            }
            for (int y=1; y<=abs(posts[x].second-loc.second); y++) {
                grid[loc.first][loc.second+dir*y]=steps;
                steps++;
            }
            loc=posts[x];
        }
        if (loc.second==posts[x].second) {
            int dir=1;
            if (posts[x].first-loc.first<0) {
                dir=-1;
            }
            for (int y=1; y<=abs(posts[x].first-loc.first); y++) {
                grid[loc.first+dir*y][loc.second]=steps;
                steps++;
            }
            loc=posts[x];
        }
    }
    if (loc.first==posts[0].first) {
        int dir=1;
        if (posts[0].second-loc.second<0) {
            dir=-1;
        }
        for (int y=1; y<abs(posts[0].second-loc.second); y++) {
            grid[loc.first][loc.second+dir*y]=steps;
            steps++;
        }
        loc=posts[0];
    }
    if (loc.second==posts[0].second) {                                                                           
        int dir=1;
        if (posts[0].first-loc.first<0) {
            dir=-1;
        }
        for (int y=1; y<abs(posts[0].first-loc.first); y++) {
            grid[loc.first+dir*y][loc.second]=steps;
            steps++;
        }
        loc=posts[0];
    }
    steps--;
    for (int x=0; x<n; x++) {
        int startx,starty,endx,endy;
        cin>>startx>>starty>>endx>>endy;
        int diff=abs(grid[endx][endy]-grid[startx][starty]);
        int diffcomp=abs(steps-diff);
        cout<<min(diff,diffcomp)<<endl;
    }
    return 0;
    for (int x=0; x<100; x++) {
        for (int y=0; y<100; y++) {
            cout<<grid[x][y]<<" ";
        }
        cout<<endl;
    }
}
