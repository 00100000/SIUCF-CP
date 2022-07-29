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
	int n, k;
	string s;
	cin >> n >> k >> s;

	stack<int> ans;
	int left = n;
	for (int i = 0; i < n; i++) {
		// pop numerically lower numbers unless there aren't enough elements left
		while (left > k && ans.size() > 0 && ans.top() < s.at(i) - '0') {
			ans.pop();
			left--;
		}
		ans.push(s.at(i) - '0');
	}
	// remove extra from top
	while ((int)ans.size() > k) ans.pop();
	// build answer
	vector<int> print(k);
	for (int i = k - 1; i >= 0; i--) {
		print[i] = ans.top();
		ans.pop();
	}
	for (int i = 0; i < k; i++) cout << print[i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
