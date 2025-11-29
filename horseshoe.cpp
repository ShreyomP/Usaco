// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

int ans=0;

void floodfilly(int n, int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int count, int countwo) {
    if (countwo==count) {
        ans=max(ans,countwo*2);
        return;
    }
    for (auto it : dir) {
        int newx=x+it.first;
        int newy=y+it.second;
        if ((newx>=0 && newx<n) && (newy>=0 && newy<n)) {
            if (!visited[newx][newy] && grid[newx][newy]==')') {
                visited[newx][newy]=true;
                floodfilly(n,newx,newy,grid,visited,count,countwo+1);
                visited[newx][newy]=false;
            }
        }
    }
}


void floodfillx(int n, int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int count) {
    for (auto it : dir) {
        int newx=x+it.first;
        int newy=y+it.second;
        if ((newx>=0 && newx<n) && (newy>=0 && newy<n)) {
            if (!visited[newx][newy] && grid[newx][newy]=='(') {
                visited[newx][newy]=true;
                floodfillx(n,newx,newy,grid,visited,count+1);
                visited[newx][newy]=false;
            }
            if (!visited[newx][newy] && grid[newx][newy]==')') {
                int two=0;
                floodfilly(n,newx,newy,grid,visited,count+1,two);
                visited[newx][newy]=false;
            }
        }
    }
}

int main() {
    ifstream in("hshoe.in");
    ofstream out("hshoe.out");
    int n;
    in>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            in>>grid[x][y];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(n));
    visited[0][0]=true;
    floodfillx(n,0,0,grid,visited,0);
    out<<ans;
}
