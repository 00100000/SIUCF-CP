#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n, g;
		cin >> n >> g;
		n++;
		vector<int> s(n);
		s[0] = 0;
		for (int j = 1; j < n; j++) {
			cin >> s[j];
			s[j] += s[j - 1];
		}
		//for (int j = 0; j < n; j++) cout << s[j] << ", ";
		for (int j = 0; j < g; j++) {
			int w, t;
			cin >> w >> t;
			int cnt = 0;
			for (int k = 0; k < n - w - 1; k++) {
				if (t <= (s[k + w] - s[k]) / w) cnt++;
			}
			cout << cnt << "\n";
		}
	}

	return 0;
}
