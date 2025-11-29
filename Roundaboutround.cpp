#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		int digits = 1;
		int begin = 5;
		int end = 49;
		int ans = 0;
		while (digits < 100000000) {
			digits *= 10;
			begin += 4 * digits;
			end = 5 * digits - 1;
			ans += max(min(end, n) - max(begin, 2) + 1, 0);
		}
		cout << ans << endl;
	}
	return 0;
}
