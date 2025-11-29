#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	ifstream in("mountains.in");
	ofstream out("mountains.out");
	long long n;
	in >> n;
	vector<pair<long long, long long>> peaks(n);
	for (long long i = 0; i < n; ++i) {
		in >> peaks[i].first >> peaks[i].second;
	}
	sort(peaks.begin(), peaks.end(), greater<pair<long long, long long>>());
	vector<int> covered(n, 0);
	long long ans = 0;
	for (long long x = 0; x < n; x++) {
		for (long long y = x + 1; y < n; y++) {
			if (abs(peaks[y].first - peaks[x].first) <= abs(peaks[y].second - peaks[x].second) && covered[y]==0) {
				covered[y] = 1;
				ans++;
			}
		}
	}
	out << n-ans;
}