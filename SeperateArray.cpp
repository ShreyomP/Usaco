#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool works(long long max, long long m, vector<long long> nums) {
	long long current_sum = 0;
	long long required_subarrays = 1;
	for (long long x : nums) {
		if (x>max) {
			return false;
		}
		if (current_sum + x <= max) {
			current_sum += x;
		} else {
			required_subarrays++;
			current_sum = x;
		}
	}
	return required_subarrays<=m;
}


int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> nums(n);
	long long high = 0;
	for (long long x=0; x<n; x++) {
		cin >> nums[x];
		high += nums[x];
	}
	long long low = *max_element(nums.begin(), nums.end());
	long long ans = 0;
	while (low<= high) {
		long long mid = low + (high - low) / 2;
		if (works(mid, m, nums)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << ans;
}