#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int location(string cow, vector<string> permutaion) {
    for (int x=0; x<8; x++) {
        if (permutaion[x]==cow) {
            return x;
        }
    }
}


bool isvalid(vector<string> permutation, int n, vector<string> cowone, vector<string> cowtwo) {
    for (int x=0; x<n; x++) {
        if (location(cowone[x], permutation)-location(cowtwo[x], permutation)!=1 && location(cowone[x], permutation)-location(cowtwo[x], permutation)!=-1) {
            return false;
        }
    }
    return true;
}


int main() {
    ifstream in("lineup.in");
    ofstream out("lineup.out");
    int n;
    in>>n;
    vector<string> cowone(n);
    vector<string> cowtwo(n);
    for (int x=0; x<n; x++) {
        string yap;
        in>>cowone[x];
        in>>yap;
        in>>yap;
        in>>yap;
        in>>yap;
        in>>cowtwo[x];
    }
    vector<string> input = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    
    sort(input.begin(), input.end());
    
    do {
        if (isvalid(input, n, cowone, cowtwo)==true) {
            for (int x=0; x<8; x++) {
                out<<input[x]<<endl;
            }
            return 0;
        }

    } while (next_permutation(input.begin(), input.end()));




    return 0;
}