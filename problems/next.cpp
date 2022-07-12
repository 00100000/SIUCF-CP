#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		string s;
		cin >> s;
		vector<char> backward(3);
		bool carry = true;
		for (int j = 0; j < 3; j++) {
			backward[j] = s.at(j);
		}
		for (int j = 2; j >= 0 && carry; j--) {
			backward[j] = (backward[j] + 1 - 'A') % 26 + 'A';
			if (backward[j] != 'A') carry = false;
		}
		for (int j = 0; j < 3; j++) cout << backward[j];
		cout << "\n";
	}

	return 0;
}
