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

#define all(x) (x).begin(),(x).end()
#define sz(x) ((ll)x.size())
#define szll(x) ((ll)x.size())
#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto i:x)cout<<i<<" ";cout<<endl
#define f first
#define s second
#define ins insert
#define FOR(i, j, k, in) for(ll i=j;i<k;i+=in)
#define FORLL(i, j, k, in) for(long long i=j;i<k;i+=in)
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;

ll n;
vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
vector<bool> vis;
// stupid cheese
void dfs(int node) {
	if (vis[node]) {
		return;
	} else {
		vis[node] = true;
		for (auto i : adj[node]) {
			if (!vis[i.f]) {
				dfs(i.f);
			}
		}
	}
}

ll dijkstra(ll h, ll s, ll w) {
	// check if in same components
	dfs(h);
	if (!vis[s]) return -1;
	FOR(i, 0, n, 1) vis[i] = false;
	dfs(s);
	if (!vis[w]) return -1;
	FOR(i, 0, n, 1) vis[i] = false;
	// actual dijkstra
	ll totaldist = 0;

	priority_queue<pair<ll, ll>> q;
	FOR(i, 0, n, 1) dist[i] = 1e9;
	dist[h] = 0;
	q.push(mp(0, h));
	while (!q.empty()) {
		ll node = q.top().s;
		q.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto j : adj[node]) {
			ll b = j.f, t = j.s;
			if (dist[node] + t < dist[b]) {
				dist[b] = dist[node] + t;
				q.push(mp(-dist[b], b));
			}
		}
	}
	totaldist += dist[s];
	// reset vars
	q = priority_queue<pair<ll, ll>>();
	FOR(j, 0, n, 1) {
		dist[j] = 1e9;
		vis[j] = false;
	}

	dist[s] = 0;
	q.push(mp(0, s));
	while (!q.empty()) {
		ll node = q.top().s;
		q.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto j : adj[node]) {
			ll b = j.f, t = j.s;
			if (dist[node] + t < dist[b]) {
				dist[b] = dist[node] + t;
				q.push(mp(-dist[b], b));
			}
		}
	}
	totaldist += dist[w];
	return totaldist;
}

void solve() {
	ll e, p;
	cin >> n >> e >> p;
	adj.resize(n);
	dist.resize(n);
	vis.resize(n);
	FOR(i, 0, e, 1) {
		ll a, b, t;
		cin >> a >> b >> t;
		a--;
		b--;
		adj[a].pb(mp(b, t));
		adj[b].pb(mp(a, t));
	}
	FOR(i, 0, p, 1) {
		ll h, s, w;
		cin >> h >> s >> w;
		h--;
		s--;
		w--;
		cout << dijkstra(h, s, w) << "\n";
		// reset vars
		FOR(j, 0, n, 1) {
			dist[j] = 0;
			vis[j] = false;
		}
	}
	FOR(j, 0, n, 1) adj[j].clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;cin>>t;while(t-->0)solve();
	return 0;
}
