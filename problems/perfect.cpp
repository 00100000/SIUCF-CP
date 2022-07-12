#include <algorithm>
#include <iostream>
#include <math.h>
#include <utility>
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
		vector<pair<double, double>> coins(n + 1);
		coins[0] = make_pair(0, 0);
		for (int j = 1; j < n + 1; j++) {
			double a, b;
			cin >> a >> b;
			coins[j] = make_pair(a, b);
		}
		sort(coins.begin(), coins.end());
		double dist = 0;
		for (int j = 1; j < n + 1; j++) {
			dist += sqrt(pow(coins[j].first - coins[j - 1].first, 2) + pow(coins[j].second - coins[j - 1].second, 2));
		}
		cout << fixed << dist << "\n";
	}

	return 0;
}
