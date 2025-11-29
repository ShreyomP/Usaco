#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct dsu {
    vector<int> p, s;
    dsu(int n) {
        p.resize(n);
        s.assign(n,1);
        for (int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){
        if (p[x]==x) return x;
        return p[x]=find(p[x]);
    }
    void join(int a,int b){
        a=find(a); b=find(b);
        if (a==b) return;
        if (s[a]<s[b]) swap(a,b);
        p[b]=a;
        s[a]+=s[b];
    }
};




int main() {
    //ifstream in("wormsort.in");
    //ofstream out("wormsort.out");
	int n,m;
    cin>>n>>m;
    vector<int> cows(n);
    for (int x=0; x<n; x++) {
        cin>>cows[x];
        cows[x]--;
    }
    vector<int> copy=cows;
    sort(copy.begin(),copy.end());
    if (copy==cows) {
        cout<<-1;
        return 0;
    }
    vector<pair<int,pair<int,int>>> holes(m);
    int big=-1;
    for (int x=0; x<m; x++) {
        cin>>holes[x].second.first>>holes[x].second.second>>holes[x].first;
        holes[x].second.first--;
        holes[x].second.second--;
        big=max(big,holes[x].first);
    }
    int low=0;
    int high=big;
    int ans=-1;
    while (low<=high) {
        int mid=(low+high)/2;
        dsu x(n);
        for (auto it : holes) {
            if (it.first>=mid) {
                x.join(it.second.first,it.second.second);
            }
        }
        bool works=true;
        for (int a=0; a<n; a++) {
            if (x.find(a)!=x.find(cows[a])) {
                works=false;
            }
        }
        if (works) {
            low=mid+1;
            ans=mid;
        }
        else {
            high=mid-1;
        }
    }
    cout<<ans;
}
