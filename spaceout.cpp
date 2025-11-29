// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    vector<vector<int>> field(n,vector<int>(n));
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            cin>>field[x][y];
        }
    }
    int maxim=0;
    int rowalt=0,colalt=0;
    for (int x=0; x<n; x++) {
        vector<int> sum(2);
        for (int y=0; y<n; y++) {
            sum[y%2]+=field[x][y];
        }
        rowalt+=max(sum[0],sum[1]);
    }
    for (int x=0; x<n; x++) {
        vector<int> sum(2);
        for (int y=0; y<n; y++) {
            sum[y%2]+=field[y][x];
        }
        colalt+=max(sum[0],sum[1]);
    }
    cout<<max(rowalt,colalt);
}
