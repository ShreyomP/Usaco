#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool doesitwork(long long mask, vector<long long> cows, vector<pair<pair<long long, long long>, pair<long long, long long>>> aircon) {
    for (long long a = 0; a < aircon.size(); a++) {
        if (mask & (1LL << a)) {
            for (long long x = aircon[a].first.first; x < aircon[a].first.second; x++) {
                cows[x] -= aircon[a].second.first;
            }
        }
    }
    for (long long x = 0; x < cows.size(); x++) {
        if (cows[x] > 0) return false;
    }
    return true;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> cows(101);
    for (long long x = 0; x < n; x++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--;
        for (long long y = a; y < b; y++) {
            cows[y] = max(cows[y], c);
        }
    }

    vector<pair<pair<long long, long long>, pair<long long, long long>>> airCond(m);
    for (long long x = 0; x < m; x++) {
        cin >> airCond[x].first.first >> airCond[x].first.second >> airCond[x].second.first >> airCond[x].second.second;
        airCond[x].first.first--;
    }

    long long cheapest = LLONG_MAX;
    long long total = 1LL << m;
    for (long long mask = 0; mask < total; mask++) {
        if (doesitwork(mask, cows, airCond)) {
            long long cost = 0;
            for (long long a = 0; a < m; a++) {
                if (mask & (1LL << a)) cost += airCond[a].second.second;
            }
            cheapest = min(cheapest, cost);
        }
    }
    cout << cheapest;
    return 0;
}
