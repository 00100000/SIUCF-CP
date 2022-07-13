#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool cmp(const pair<int, long long> &a, const pair<int, long long> &b){
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n, k;
		cin >> n >> k;
		n++;
		// prefix sum
		vector<int> x(n);
		x[0] = 0;
		for (int j = 1; j < n; j++) {
			cin >> x[j];
			x[j] += x[j - 1];
		}

		vector<pair<int, long long>> sum(n - k);
		for (int j = 1, l = k; l < n; j++, l++) {
			sum[j - 1] = make_pair(j, x[l] - x[j - 1]);
		}
		sort(sum.begin(), sum.end(), cmp);

		for (int j = 0; j < n - k; j++) {
			cout << sum[j].first << " ";
		}
		cout << "\n";
	}

	return 0;
}
