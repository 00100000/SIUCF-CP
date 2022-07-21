#include <iostream>
#include <vector>
using namespace std;

int solve(int t, int p) {
	return t * p / 60;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int t, p;
		cin >> t >> p;
		cout << solve(t, p) << "\n";
	}

	return 0;
}
