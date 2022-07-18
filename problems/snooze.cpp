#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long c;
	cin >> c;
	for (long long i = 0; i < c; i++) {
		long long n, l;
		cin >> n >> l;

		vector<long long> exe(n);
		for (long long j = 0; j < n; j++) cin >> exe[j];
		sort(exe.begin(), exe.end());
		vector<long long> spaces(n - 1);
		for (long long j = 0; j < n - 1; j++) spaces[j] = exe[j + 1] - exe[j] - 1;
		sort(spaces.begin(), spaces.end());

		map<long long, long long> m;
		for (long long j = n - 2; j >= 0; j--) m[spaces[j]] = n - 1 - j;

		long long maxTime = 0;
		for (auto j = m.begin(); j != m.end(); j++) maxTime = max(maxTime, j->first * j->second);

		cout << maxTime << "\n";
	}

	return 0;
}
