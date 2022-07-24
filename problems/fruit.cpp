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
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto i:x)cout<<i<<" ";cout<<endl
#define dbglppr(x) cout<<(#x)<<":"<<endl;for(auto i:x)cout<<i.first<<", "<<i.second<<endl;cout<<endl
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	// no need to track the grid, the fruits are "checkpoints" we must get to
	vector<pair<int, int>> checkpts;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s.at(j) != '.') checkpts.push_back({i, j});
		}
	}
	int sz = checkpts.size();
	vector<int> perm(sz);
	for (int i = 0; i < sz; i++) perm[i] = i;

	int minDist = INT_MAX;
	do {
		int dist = 0;
		pair<int, int> last = {0, 0};
		for (int i = 0; i < sz; i++) {
			// manhattan distance
			dist += abs(last.first - checkpts[perm[i]].first) + abs(last.second - checkpts[perm[i]].second);
			last = checkpts[perm[i]];
		}
		// bottom right
		dist += abs(last.first - n) + abs(last.second - m) - 2;
		minDist = min(minDist, dist);
	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << minDist << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
