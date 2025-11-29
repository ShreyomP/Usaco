// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
using namespace std;


int main() {
    ifstream in("msched.in");
    ofstream out("msched.out");
	int n;
    in>>n;
    vector<pair<int,int>> cows(n);
    for (int x=0; x<n; x++) {
        in>>cows[x].second>>cows[x].first;
    }
    sort(cows.begin(), cows.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    });

    priority_queue<int> q;
    int cow=0;
    int ans=0;
    for (int t=10000; t>0; t--) {
        while (cow<n && t<=cows[cow].first) {
            q.push(cows[cow].second);
            cow++;
        }
        if (q.size()>0) {
            ans+=q.top();
            q.pop();
        }
    }
    out<<ans;
}
