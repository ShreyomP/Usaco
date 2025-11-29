// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

void floodfill(int &count, int n, int m, int x, int y, int d, vector<vector<int>> &elev, vector<vector<int>> &waypoint, vector<vector<int>> &visited) {
    if (waypoint[x][y]==1) {
        count++;
    }
    for (auto it : dir) {
        int newx=x+it.first;
        int newy=y+it.second;
        if ((newx>=0 && newx<n) && (newy>=0 && newy<m)) {
            if (visited[newx][newy]==0 && abs(elev[newx][newy]-elev[x][y])<=d) {
                visited[newx][newy]=1;
                floodfill(count,n,m,newx,newy,d,elev,waypoint,visited);
            }
        }
    }
}

bool works(int total, int d, vector<vector<int>> &elev,pair<int,int> start, vector<vector<int>> &waypoint) {
    vector<vector<int>> visited(waypoint.size(),vector<int>(waypoint[0].size()));
    int count=0;
    visited[start.first][start.second]=1;
    floodfill(count,elev.size(),elev[0].size(),start.first,start.second,d,elev,waypoint,visited);
    if (count==total) {
        return true;
    }
    return false;
}

int main() {
    ifstream in("ccski.in");
    ofstream out("ccski.out");
	int m,n;
    in>>m>>n;
    vector<vector<int>> elev(m,vector<int>(n));
    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
            in>>elev[x][y];
        }
    }
    vector<vector<int>> waypoint(m,vector<int>(n));
    int total=0;
    pair<int,int> start={0,0};
    for (int x=0; x<m; x++) {
        for (int y=0; y<n; y++) {
            in>>waypoint[x][y];
            if (waypoint[x][y]==1) {
                total++;
                start.first=x;
                start.second=y;
            }
        }
    }
    int low=0;
    int high=1000000000;
    int ans=high;
    while (low<=high) {
        int mid=(low+high)/2;
        if (works(total,mid,elev,start,waypoint)) {
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    out<<ans;
}
