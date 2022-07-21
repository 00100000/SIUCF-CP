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
#define sz(x) ((int)x.size())
#define szll(x) ((ll)x.size())
#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto i:x)cout<<i<<" ";cout<<endl
#define f first
#define s second
#define ins insert
#define FOR(i, j, k, in) for(int i=j;i<k;i+=in)
#define FORLL(i, j, k, in) for(long long i=j;i<k;i+=in)
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef long double ld;

void solve() {
	string str;
	cin >> str;
	if (str.compare("CAR") == 0) {
		cout << "Arup\n";
		return;
	}
	FOR(i, 0, sz(str) - 2, 1) {
		if (str.at(i) == 'C' && str.at(i + 1) == 'A' && str.at(i + 2) == 'R') {
			cout << "Travis\n";
			return;
		}
	}
	cout << "Unknown\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.exceptions(cin.failbit);
	int t;cin>>t;while(t-->0)solve();
	return 0;
}
