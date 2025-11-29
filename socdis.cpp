// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("socdist1.in");
    ofstream out("socdist1.out");
	int n;
    in>>n;
    string cows;
    in>>cows;
    int longest=0;
    int secondlongest=0;
    int curr=0;
    for (int x=0; x<n; x++) {
        if (cows[x]=='1') {
            if (curr>=longest) {
                secondlongest=longest;
                longest=curr;
            }
            else if (curr>=secondlongest) {
                secondlongest=curr;
            }
            curr=0;
        }
        if (cows[x]=='0') {
            curr++;
        }
    }
    if (curr>=longest) {
        secondlongest=longest;
        longest=curr;
    }
    else if (curr>=secondlongest) {
        secondlongest=curr;
    }
    //cout<<longest<<" "<<secondlongest<<endl;
    int onelong=floor((longest-1)/2);
    int twolong=floor((secondlongest-1)/2);
    //cout<<onelong<<" "<<twolong;
    int dublong=floor((longest-2)/3);
    //cout<<endl<<dublong;
    if (twolong>dublong) {
        out<<twolong+1;
        return 0;
    }
    else {
        out<<dublong+1;
        return 0;
    }
}
