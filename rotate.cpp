// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void mix(vector<int> &activepos, vector<int> &cows) {
    int old=cows[activepos[activepos.size()-1]];
    cows[activepos[0]]=cows[activepos[cows.size()-1]];
    for (int x=activepos.size()-1; x>0; x--) {
        cows[activepos[x]]=cows[activepos[x-1]];
    }
    //cout<<old<<endl<<endl;
    cows[activepos[0]]=old;
    for (int x=0; x<activepos.size(); x++) {
        activepos[x]++;
        activepos[x]=activepos[x]%cows.size();
    }
    //cows[activepos[activepos.size()]]=old;
}

int main() {
	int n,k,t;
    cin>>n>>k>>t;
    vector<int> activepos(k);
    vector<int> cows(n);
    for (int x=0; x<n; x++) {
        cows[x]=x;
    }
    for (int x=0; x<k; x++) {
        cin>>activepos[x];
    }
    
    for (int x=0; x<t; x++) {
        vector<int> ans;
        for (int y=0; y<k; y++) {
            ans.push_back(cows[activepos[y]]);
        }
        for (int y=0; y<k; y++) {
            cows[activepos[y]]=ans[(y-1+(ans.size()))%(ans.size())];
        }
        for (int y=0; y<k; y++) {
            activepos[y]=(activepos[y]+1)%n;
        }
    }
    for (int x=0; x<n; x++) {
        cout<<cows[x];
        if (x<n-1) {
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
    /*
    for (int x=0; x<t; x++) {
        mix(activepos,cows);
        for (int x=0; x<n; x++) {
            cout<<cows[x]<<" ";
        }
        cout<<endl;
        for (int x=0; x<k; x++) {
            cout<<activepos[x]<<" ";
        }
        cout<<endl<<endl;
    }
    */
}
