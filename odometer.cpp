#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("odometer.in");
    ofstream out("odometer.out");
    long long a,b;
    in>>a>>b;
    long long moos=0;
    int maxLen=to_string(b).size();
    for(int len=1;len<=maxLen;len++){
        for(int base=0;base<=9;base++){
            for(int x=0;x<len;x++){
                for(int d=0;d<=9;d++){
                    if(d!=base){
                        long long check=0;
                        for(int i=0;i<len;i++){
                            if(i==x) check=check*10+d;
                            else check=check*10+base;
                        }
                        if(to_string(check).size()==len && check>=a && check<=b){
                            moos++;
                            //out<<check<<endl;
                        }
                    }
                }
            }
        }
    }
    out<<moos<<endl;
}
