#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		vector<int> heights(n);
		for (int j = 0; j < n; j++) cin >> heights[j];
		sort(heights.begin(), heights.end());

		long long total = 0;
		int last = INT_MAX;
		for (int j = n - 1; j >= 0; j--) {
			if (heights[j] + 2 <= last) {
				total += heights[j];
				last = heights[j];
			}
		}

		cout << total << "\n";
	}

	return 0;
}
