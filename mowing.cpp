// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("mowing.in");
    //ofstream out("mowing.out");
	int n;
    cin>>n;
    vector<vector<int>> lastvisitedfield(2001,vector<int>(2001, -1));
    int farmerjohnx=1000;
    int farmerjohny=1000;
    lastvisitedfield[1000][1000]=0;
    int time=0;
    int score=99999;
    for (int x=0; x<n; x++) {
        char direction;
        cin>>direction;
        int steps=0;
        cin>>steps;
        int changex=0;
        int changey=0;
        if (direction=='N') {
            changex=1;
        }
        else if (direction=='S') {
            changex=-1;
        }
        else if (direction=='W') {
            changey=-1;
        }
        else {
            changey=1;
        }
        for (int y=0; y<steps; y++) {
            farmerjohnx+=changex;
            farmerjohny+=changey;
            time++;
            if (lastvisitedfield[farmerjohnx][farmerjohny]>=0 && (time-lastvisitedfield[farmerjohnx][farmerjohny])<score) {
                score=(time-lastvisitedfield[farmerjohnx][farmerjohny]);
            }
            lastvisitedfield[farmerjohnx][farmerjohny]=time;
        }
    }
    if (score==99999) {
        cout<<-1;
    }
    else {
        cout<<score;
    }
	

    return 0;
}
