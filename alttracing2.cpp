#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
    cin>>n;
    string cows;
    cin>>cows;
    int size=0, start=0, end=0;
    int maxdays=0,curdays=0;
    for (int x=0; x<n; x++) {
        if (cows[x]=='1') {
            int y=x;
            while (y<n && cows[y]=='1') {
                y++;
            }
            size=y-x;
            start=x;
            end=y-1;
            if (start==0 || end==n-1) {
                maxdays = max(maxdays, size-1);
            }
            else {
                maxdays = min(maxdays, (size-1)/2);
            }
            x=y;
        }
        else {
            x++;
        }
    }
    //maxdays=1;
    int minsource=0;
    for (int x=0; x<n; x++) {
        if (cows[x]=='0') {
            continue;
        }
        int start=x;
        while (x<n && cows[x]=='1') {
            x++;
        }
        int end=x-1;
        int pos=start;
        while (pos<=end) {
            int source=min(end,pos+maxdays);
            minsource++;
            pos=source+maxdays+1;
        }
    }
    cout<<minsource;
}
