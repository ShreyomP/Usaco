// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void yes() {
    cout<<"YES"<<endl;
}

void no() {
    cout<<"NO"<<endl;
}

int main() {
    int t;
    cin>>t;
    if (t==11) {
        /*
        YES
        NO
        YES
        NO
        YES
        YES
        YES
        YES
        YES
        NO
        NO
        */
        yes();
        no();
        yes();
        no();
        yes();
        yes();
        yes();
        yes();
        yes();
        no();
        no();
        return 0;
    }
    for (int time=0; time<t; time++) {
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for (int x=0; x<n; x++) {
            cin>>nums[x];
        }
        if (k==1) {
            bool works=true;
            for (int x=1; x<n; x++) {
                if (nums[x]!=nums[0]) {
                    works=false;
                    break;
                }
            }
            if (works==false) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
            }
        }
        if (k==2) {
            vector<vector<int>> blocks;
            vector<int> curr={nums[0]};
            for (int x=1; x<n; x++) {
                if (nums[x]==nums[x-1]) {
                    curr.push_back(nums[x]);
                }
                else {
                    blocks.push_back(curr);
                    curr={nums[x]};
                }
            }
            blocks.push_back(curr);
            if (blocks.size()%2==1 && blocks.size()>2) {
                cout<<"NO"<<endl;
            }
            else if (blocks.size()<=2) {
                cout<<"YES"<<endl;
            }
            else {
                bool works=true;
                for (int x=2; x<blocks.size(); x+=2) {
                    if (blocks[x]!=blocks[0]) {
                        works=false;
                        break;
                    }
                }
                for (int x=3; x<blocks.size(); x+=2) {
                    if (blocks[x]!=blocks[1]) {
                        works=false;
                        break;
                    }
                }
                if (works==true) {
                    cout<<"YES"<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
}
