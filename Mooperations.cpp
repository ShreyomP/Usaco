#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int time = 0; time < n; time++) {
		string word;
		cin >> word;
		int best = word.size()+10;
		for (int x = 1; x < word.size() - 1; x++) {
			if (word[x] == 'O') {
				int count = word.size() - 1;
				if (word[x + 1] == 'O') {
					count--;
				}
				if (word[x - 1] == 'M') {
					count--;
				}
				best = min(best, count);
			}
		}
		if (best == word.size() + 10) {
			cout << -1 << endl;
		}
		else {
			cout << best << endl;
		}
	}
}