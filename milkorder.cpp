#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("milkorder.in");
    ofstream out("milkorder.out");
    int n,m,k;
    in>>n>>m>>k;
    vector<int> heiarchy(m);
    for (int i=0; i<m; i++) {
        in>>heiarchy[i];
    }
    vector<pair<int,int>> demand(k);
    for (int i=0; i<k; i++) {
        in>>demand[i].first>>demand[i].second;
        demand[i].second--;
    }
    vector<int> stall(n,0);
    vector<int> pos(n+1,-1);
    for (auto p:demand) {
        stall[p.second]=p.first;
        pos[p.first]=p.second;
    }
    if (pos[1]!=-1) {
        out<<pos[1]+1;
        return 0;
    }
    vector<int> inH(n+1,0);
    for (int i=0; i<m; i++) {
        inH[heiarchy[i]]=1;
    }
    int anchor=-1;
    int anchorPos=-1;
    for (int i=0; i<m; i++) {
        if (pos[heiarchy[i]]!=-1) {
            anchor=i;
            anchorPos=pos[heiarchy[i]];
            break;
        }
    }
    if (anchor!=-1) {
        int cur=anchorPos-1;
        for (int i=anchor-1; i>=0; i--) {
            int cow=heiarchy[i];
            while (cur>=0 && stall[cur]!=0) {
                cur--;
            }
            stall[cur]=cow;
            pos[cow]=cur;
            if (cow==1) {
                out<<cur+1;
                return 0;
            }
            cur--;
        }
        cur=anchorPos+1;
        for (int i=anchor+1; i<m; i++) {
            int cow=heiarchy[i];
            if (pos[cow]!=-1) {
                if (cur<=pos[cow]) {
                    cur=pos[cow]+1;
                }
            } else {
                while (cur<n && stall[cur]!=0) {
                    cur++;
                }
                stall[cur]=cow;
                pos[cow]=cur;
                if (cow==1) {
                    out<<cur+1;
                    return 0;
                }
                cur++;
            }
        }
        if (!inH[1]) {
            for (int i=0; i<n; i++) {
                if (stall[i]==0) {
                    out<<i;
                    return 0;
                }
            }
        }
        return 0;
    } else {
        if (inH[1]) {
            int cur=0;
            for (int i=0; i<m; i++) {
                int cow=heiarchy[i];
                while (cur<n && stall[cur]!=0) {
                    cur++;
                }
                stall[cur]=cow;
                pos[cow]=cur;
                if (cow==1) {
                    out<<cur+1;
                    return 0;
                }
                cur++;
            }
            return 0;
        } else {
            int cur=0;
            for (int i=0; i<m; i++) {
                int cow=heiarchy[i];
                while (cur<n && stall[cur]!=0) {
                    cur++;
                }
                stall[cur]=cow;
                pos[cow]=cur;
                cur++;
            }
            for (int i=0; i<n; i++) {
                if (stall[i]==0) {
                    out<<i+1;
                    return 0;
                }
            }
            return 0;
        }
    }
}
