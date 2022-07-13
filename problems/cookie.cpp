#include <iostream>
#include <vector>
using namespace std;

long long maxll(long long a, long long b) {
	if (a > b) return a;
	return b;
}

long long minll(long long a, long long b) {
	if (a < b) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long c, s, o, p;
		cin >> c >> s >> o >> p;

		long long rm = minll(c, min(s, o));
		long long sec_rm = 0;
		if (c - rm == 0) sec_rm = minll(s - rm, o - rm);
		if (s - rm == 0) sec_rm = minll(c - rm, o - rm);
		if (o - rm == 0) sec_rm = minll(c - rm, s - rm);
		
		cout << maxll(p - rm - sec_rm, 0) << "\n";
	}

	return 0;
}
