#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		long long s, n, k;
		cin >> s >> n >> k;
		cout << (s + k - 1) % n + 1 << "\n";
	}

	return 0;
}
