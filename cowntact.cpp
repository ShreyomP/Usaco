// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("tracing.in");
    ofstream out("tracing.out");
	int n,t;
    in>>n>>t;
    vector<int> cows(n);
    string temp;
    in>>temp;
    for (int x=0; x<n; x++) {
        cows[x]=temp[x]-'0';
    }
    vector<pair<int,pair<int,int>>> inters(t);
    for (int x=0; x<t; x++) {
        in>>inters[x].first>>inters[x].second.first>>inters[x].second.second;
    }
    sort(inters.begin(),inters.end());
    int posscows=0;
    int mintime=100000,maxtime=0;
    for (int x=0; x<n; x++) {
        bool can=false;
        for (int time=0; time<=250; time++) {
            vector<int> infec(n);
            vector<int> numshakes(n);
            infec[x]=1;
            for (int y=0; y<t; y++) {
                int a=inters[y].second.first;
                int b=inters[y].second.second;
                a--;
                b--;
                if (infec[a]==1) {
                    numshakes[a]++;
                }
                if (infec[b]==1) {
                    numshakes[b]++;
                }
                if (infec[a]==1 && numshakes[a]<=time) {
                    infec[b]=1;
                }
                if (infec[b]==1 && numshakes[b]<=time) {
                    infec[a]=1;
                }
            }
            bool works=true;
            for (int e=0; e<n; e++) {
                if (infec[e]!=cows[e]) {
                    works=false;
                    break;
                }
            }
            if (works==true) {
                can=true;
                mintime=min(mintime,time);
                maxtime=max(maxtime,time);
            }
        }
        if (can==true) {
            posscows++;
        }
    }
    if (maxtime==250) {
        out<<posscows<<" "<<mintime<<" Infinity";
        return 0;
    }

    out<<posscows<<" "<<mintime<<" "<<maxtime;
}
