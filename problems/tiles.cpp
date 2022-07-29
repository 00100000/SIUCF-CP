#include <algorithm>
#include <cassert>
#include <bitset>
#include <deque>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto z:x)cout<<z<<" ";cout<<endl
typedef long long ll;

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	// count inversions
	int inv = 0;
	for (int i = 0; i < n; i++) {
		set<char> behind;
		for (int j = i + 1; j < n; j++) behind.insert(s.at(j));
		for (int j = 0; j < n; j++) {
			if (s.at(i) == t.at(j)) {
				for (int k = j + 1; k < n; k++) {
					if (behind.find(t.at(k)) == behind.end()) inv++;
				}
				break;
			}
		}
	}
	cout << inv << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
