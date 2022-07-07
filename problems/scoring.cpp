#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// I am convinced this is a floating point math troll
double solve(int n, int s, int h, vector<double> scores) {
	double dividend = 0;
	double divisor = n - s - h;
	for (int i = s; i < n - h; i++) {
		dividend += scores[i];
	}
	return dividend/divisor;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, s, h;
		cin >> n >> s >> h;
		vector<double> scores(n);
		for (int j = 0; j < n; j++) {
			double temp;
			cin >> temp;
			scores[j] = temp;
		}
		sort(scores.begin(), scores.end());
		cout << fixed << solve(n, s, h, scores) << "\n";
	}
	return 0;
}
