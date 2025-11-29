// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool works(int pos1, int pos2, int pos3, vector<vector<int>> &spot, vector<vector<int>> &cow, int n) {
    set<int> usedspot;
    for (int x=0; x<n; x++) {
        int code=spot[x][pos1]*100+spot[x][pos2]*10+spot[x][pos3];
        usedspot.insert(code);
    }
    for (int x=0; x<n; x++) {
        int code=cow[x][pos1]*100+cow[x][pos2]*10+cow[x][pos3];
        if (usedspot.count(code)) {
            return false;
        }
    }
    return true;
}


int main() {
    ifstream in("cownomics.in");
    ofstream out("cownomics.out");
	int n,m;
    in>>n>>m;
    vector<vector<int>> spotcows(n,vector<int>(m));
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            char temp;
            in>>temp;
            spotcows[x][y]=temp-'A';
        }
    }
    vector<vector<int>> cows(n,vector<int>(m));
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            char temp;
            in>>temp;
            cows[x][y]=temp-'A';
        }
    }
    int ans=0;
    for (int x=0; x<m-2; x++) {
        for (int y=x+1; y<m-1; y++) {
            for (int z=y+1; z<m; z++) {
                if (works(x,y,z,spotcows,cows,n)) {
                    ans++;
                }
            }
        }
    }
    out<<ans;
}
