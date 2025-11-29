// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

bool check(long long maxtime, vector<long long> cows, long long bussize, long long lim) {
    long long bus=1;
    long long cowtime=cows[0];
    long long index=0;
    for (long long x=0; x<cows.size(); x++) {
        if (x-index>=bussize || cows[x]-cowtime>maxtime) {
            bus++;
            cowtime=cows[x];
            index=x;
        }
    }
    if (bus>lim) {
        return false;
    }
    return true;
}

int main() {
    ifstream in("convention.in");
    ofstream out("convention.out");
	long long n,m,c;
    in>>n>>m>>c;
    vector<long long> cows(n);
    for (int x=0; x<n; x++) {
        in>>cows[x];
    }
    sort(cows.begin(),cows.end());
    long long low=0;
    long long high=pow(10,9);
    int answer=high;
    while (low<=high) {
        long long mid=(low+high+1)/2;
        if (check(mid,cows,c,m)) {
            answer=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    out<<answer;
}
