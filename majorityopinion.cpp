// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for (int a=0; a<t; a++) {
        int counter=0;
        int n;
        cin>>n;
        vector<int> cows;
        set<int> typesofhay;
        for (int x=0; x<n; x++) {
            int temp;
            cin>>temp;
            typesofhay.insert(temp);
            cows.push_back(temp);
        }
        int types=typesofhay.size();
        set<int> typehay;
        for (int x=1; x<n; x++) {
            if (cows[x-1]==cows[x] || cows[x-1]==cows[x+1]) {
                typehay.insert(cows[x-1]);
                //cout<<cows[x-1]<<" "<<a<<endl;
                counter++;
            }
        }
        
        if (counter==0) {
            counter=-1;
            cout<<counter;
        }
        else {
            int tempcounter=0;
            for (auto it : typehay) {
                if (tempcounter==0) {
                    cout<<it;
                }
                else {
                    cout<<" "<<it;
                }
                tempcounter++;
            }
        }
        
        
        cout<<endl;

    }


    return 0;
}
