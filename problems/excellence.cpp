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
		vector<int> stu(n);
		for (int j = 0; j < n; j++) cin >> stu[j];
		sort(stu.begin(), stu.end());

		int minRat = INT_MAX;
		for (int j = 0; j < n / 2; j++) {
			minRat = min(minRat, stu[n - 1 - j] + stu[j]);
		}

		cout << minRat << "\n";
	}

	return 0;
}
