#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		string temp;
		cin >> temp;
		int n = temp.size();
		long long ans = 1;
		for (int j = 2; j <= temp.size(); j++) {
			ans *= j;
		}
		cout << ans << "\n";
	}
	return 0;
}
