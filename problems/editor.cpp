#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

string neatify(string s) {
	string copy = "";
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '.' || s.at(i) == ',') continue;
		if (s.at(i) < 'a') {
			copy += s.at(i) + 'a' - 'A';
		} else {
			copy += s.at(i);
		}
	}
	return copy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		map<string, int> m;
		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;
			s = neatify(s);
			m[s]++;
		}
		pair<string, int> maxWord = make_pair("", 0);
		for (auto j : m) {
			if (j.second > maxWord.second) maxWord = make_pair(j.first, j.second);
		}

		if ((double)maxWord.second / (double)n >= 0.1) {
			cout << maxWord.first;
		} else {
			cout << "Looks good!";
		}
		cout << "\n";
	}

	return 0;
}
