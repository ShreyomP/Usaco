#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> cows(n);
    for (int x = 0; x < n; x++) {
        cin >> cows[x];
    }
    sort(cows.begin(), cows.end(), greater<int>());
    int greatest = 0;
    for (int x = 0; x < n; x++) {
        if (cows[x] > x) {
            greatest = max(greatest, x + 1);
        }
    }
    int equalcount = 0;
    for (int x = greatest - 1; x >= 0; x--) {
        if (cows[x] == greatest) {
            equalcount++;
        }
    }
    if (cows[greatest] == greatest) {
        equalcount++;
    }
    if (cows[greatest] < greatest) {
        cout << greatest;
        return 0;
    }
    if (equalcount > l) {
        cout << greatest;
        return 0;
    }
    else {
        cout << greatest + 1;
        return 0;
    }
}
