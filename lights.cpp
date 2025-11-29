// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};

void floodfill(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<vector<vector<pair<int,int>>>> &lights) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=1;
    while (!q.empty()) {
        auto cur=q.front();
        q.pop();
        for (auto it : lights[cur.first][cur.second]) {
            if (grid[it.first][it.second]==0) {
                grid[it.first][it.second]=1;
                for (auto why : directions) {
                    int newx=it.first+why.first;
                    int newy=it.second+why.second;
                    if ((newx>=0 && newx<grid.size()) && (newy>=0 && newy<grid.size())) {
                        if (visited[newx][newy]==1 && visited[it.first][it.second]==0) {
                            visited[it.first][it.second]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        for (auto it : directions) {
            int newx=cur.first+it.first;
            int newy=cur.second+it.second;
            if ((newx>=0 && newx<grid.size()) && (newy>=0 && newy<grid.size())) {
                if (grid[newx][newy]==1 && visited[newx][newy]==0) {
                    visited[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
    }
}



int main() {
    ifstream in("lightson.in");
    ofstream out("lightson.out");
	int n,m;
    in>>n>>m;
    vector<vector<int>> grid(n,vector<int>(n));
    grid[0][0]=1;
    vector<vector<vector<pair<int,int>>>> lights(n,vector<vector<pair<int,int>>>(n));
    for (int x=0; x<m; x++) {
        int a,b,c,d;
        in>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        lights[a][b].push_back({c,d});
    }
    vector<vector<int>> visited(n,vector<int>(n));
    visited[0][0]=1;
    floodfill(0,0,grid,visited,lights);
    int visit=0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            //cout<<grid[x][y]<<" ";
            if (grid[x][y]==1) {
                visit++;
            }
        }
        //cout<<endl;
    }
    out<<visit;
}
