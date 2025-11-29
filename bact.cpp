#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n=0;
    cin>>n;
    long long diff=0;
    vector<long long> bacteria(n);
    for (long long x=0; x<n; x++) {
        cin>>bacteria[x];
    }
    long long times=0;
    long long count=0;
    for (long long x=0; x<n; x++) {
        times+=count;
        bacteria[x]+=times;
        long long cur=0-bacteria[x];
        diff+=abs(cur);
        count+=cur;
        times+=cur;
    }
    cout<<diff;
}


