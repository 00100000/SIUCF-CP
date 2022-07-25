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

struct DSU {
	ll connectivity;
	vector<ll> parent;
	vector<ll> size;
	DSU(ll range) {
		connectivity = range;
		parent.resize(range);
		size.resize(range);
		for (ll i = 0; i < range; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	ll find(ll node) {
		if (node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}
	void join(ll a, ll b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (size[a] < size[b]) swap(a, b);
		connectivity += (size[a] + size[b]) * (size[a] + size[b]) - size[a] * size[a] - size[b] * size[b];
		parent[b] = a;
		size[a] += size[b];
		size[b] = size[a];
	}
};

void solve() {
	ll n, m, d;
	cin >> n >> m >> d;
	// annoying implementation
	DSU dsu(n);
	vector<pair<ll, ll>> edges(m);
	set<pair<ll, ll>> uniqueM;
	vector<ll> des(d);
	vector<ll> ans(d + 1);
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[i] = {u, v};
		uniqueM.insert({u, v});
	}
	// remove edges that will eventually be removed
	for (ll i = d - 1; i >= 0; i--) {
		cin >> des[i];
		des[i]--;
		uniqueM.erase(edges[des[i]]);
	}
	// insert permanent edges
	for (auto i : uniqueM) dsu.join(i.first, i.second);
	// add the "to be destroyed" edges to the graph in order, which will yield
	// the same result as removing those edges backwards
	for (ll i = 0; i < d; i++) {
		ans[i] = dsu.connectivity;
		pair<ll, ll> add = edges[des[i]];
		dsu.join(add.first, add.second);
	}
	ans[d] = dsu.connectivity;

	for (ll i = d; i >= 0; i--) cout << ans[i] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}
