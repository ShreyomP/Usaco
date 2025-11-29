#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

bool works(int dist, vector<pair<int, int>> cows, int num, int m) {
    int loc = cows[0].first;
    int count = 1;
    for (int x = 0; x < m; x++) {
        while (cows[x].second >= loc + dist) {
            if (loc + dist >= cows[x].first) {
                count++;
                loc = loc + dist;
            }
            else {
                loc = cows[x].first;
                count++;
            }
        }

    }
    return count >= num;

}


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cows(m);
    for (int x = 0; x < m; x++) {
        cin >> cows[x].first >> cows[x].second;
    }
    sort(cows.begin(), cows.end());
    int low = 0;
    int high = 9999999;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (works(mid, cows, n, m)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
		}
    }
    cout << ans;
}