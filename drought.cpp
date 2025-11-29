// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


void feed(vector<long long> &num, long long x, long long amount, long long &answer) {
    num[x]-=amount;
    num[x+1]-=amount;
    answer+=amount*2;
}


int main() {
	long long t;
    cin>>t;
    while (t>0) {
        t--;
        long long n;
        cin>>n;
        vector<long long> num(n);
        for (long long x=0; x<n; x++) {
            cin>>num[x];
        }
        bool works=true;
        bool cont=true;
        long long answer=0;
        while (works==true) {
            works=false;
            for (long long x=1; x<n; x++) {
                if (num[x]!=num[x-1]) {
                    works=true;
                    if (num[x]>num[x-1]) {
                        if (x+1==n) {
                            cout<<-1<<endl;
                            works=false;
                            cont=false;
                            break;
                        }
                        feed(num,x,(num[x]-num[x-1]),answer);
                    }
                    if (num[x]<num[x-1]) {
                        if (x==1) {
                            cout<<-1<<endl;
                            works=false;
                            cont=false;
                            break;
                        }
                        feed(num,x-2,(num[x-1]-num[x]),answer);
                    }
                }
            }
        }
        if (cont==true) {
            if (num[n-1]<0) {
                cout<<-1<<endl;
            }
            else {
                cout<<answer<<endl;
            }
        }
    }
}
