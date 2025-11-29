#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ifstream in("hayfeast.in");
	ofstream out("hayfeast.out");
	long long n,m;
	in >> n>>m;
	vector<pair<long long, long long>> food(n);
	for (long long x=0; x<n; x++) {
		in >> food[x].first >> food[x].second;
	}
	multiset<long long> cows;
	long long left = 0, right = 0;
	long long totalflavor = 0;
	long long smallspice = LONG_MAX;
	while (left < n) {
		while (right < n && totalflavor < m) {
			totalflavor += food[right].first;
			cows.insert(food[right].second);
			right++;
		}
		if (totalflavor >= m) {
			smallspice = min(smallspice, *cows.rbegin());
		}
		cows.erase(cows.find(food[left].second));
		totalflavor -= food[left].first;
		left++;
	}
	out << smallspice;
}