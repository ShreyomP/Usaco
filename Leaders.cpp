#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int ans = 0;
	int n;
	cin >> n;
	int hcount = 0, gcount = 0;
	vector<char> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
		if (cows[i]=='H') hcount++;
		else gcount++;
	}
	vector<int> lists(n);
	for (int i = 0; i < n; i++) {
		cin >> lists[i];
	}
	//If h<g
	int leftmost = -1;
	vector<int> hbeforelefmost;
	for (int x = 0; x < n; x++) {
		if (cows[x]=='H') {
			hbeforelefmost.push_back(x);
		}
		if (cows[x]=='G') {
			leftmost = x;
			break;
		}
	}
	int count = 0;
	for (int x = leftmost; x < lists[leftmost]; x++) {
		if (cows[x]=='G') {
			count++;
		}
	}
	if (count == gcount) {
		for (auto x : hbeforelefmost) {
			if (lists[x]-1 >= leftmost) {
				ans++;
			}
		}
	}
	//If g<h
	int hleftmost = -1;
	vector<int> gbeforelefmost;
	for (int x = 0; x < n; x++) {
		if (cows[x] == 'G') {
			gbeforelefmost.push_back(x);
		}
		if (cows[x] == 'H') {
			hleftmost = x;
			break;
		}
	}
	int newcount = 0;
	for (int x = hleftmost; x < lists[hleftmost]; x++) {
		if (cows[x] == 'H') {
			newcount++;
		}
	}
	if (newcount == hcount) {
		for (auto x : gbeforelefmost) {
			if (lists[x] - 1 >= hleftmost) {
				ans++;
			}
		}
	}
	if (newcount == hcount && count == gcount) {
		ans++;
	}
	cout << ans;
}