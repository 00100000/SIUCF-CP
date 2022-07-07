#include <iostream>
#include <vector>
using namespace std;

long long solve(int n, string s) {
	long long ans = 0;
	long long acnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.at(i) == 'C') {
			ans += acnt;
		} else {
			acnt++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		string s;
		cin >> n >> s;
		cout << solve(n, s) << "\n";
	}

	return 0;
}
