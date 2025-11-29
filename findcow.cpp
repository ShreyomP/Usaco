// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream in("cowfind.in");
    ofstream out("cowfind.out");
    string grass;
    in>>grass;
    int backfound=0;
    int ans=0;
    for (int x=0; x<grass.size()-1; x++) {
        if (grass[x]=='(' && grass[x+1]=='(') {
            backfound++;
        }
        if (grass[x]==')' && grass[x+1]==')') {
            ans+=backfound;
        }
    }
    out<<ans;
}
