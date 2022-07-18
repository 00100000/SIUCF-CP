#include <iostream>
#include <map>
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

		bool err = false;
		map<string, int> iden;

		string d;
		int t, s, l;
		for (int j = 0; j < n; j++) {
			cin >> d >> t >> s >> l;
			iden[d]++;
			if (t <= 0 || t > 30) err = true;
			if (s <= 0 || l <= 0) err = true;
			if (s % 10 != 0 || l % 10 != 0) err = true;
			if (s + l != 100) err = true;
		}
		for (auto j = iden.begin(); j != iden.end(); j++) {
			if (j->second > 1) {
				err = true;
				break;
			}
		}
		cout << (err ? "Internal Error (response 0)" : "Correct!") << "\n";
	}

	return 0;
}

