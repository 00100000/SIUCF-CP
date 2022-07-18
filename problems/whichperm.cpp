#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n;
bool solved;
vector<int> lexfirst;
vector<int> d;
vector<int> build;
vector<bool> visited;

vector<int> lexcmp(vector<int> a) {
	for (int i = 0; i < n; i++) {
		if (a[i] < lexfirst[i]) {
			return a;
		}
		if (lexfirst[i] < a[i]) {
			return lexfirst;
		}
	}
	return lexfirst;
}

void solve(int index) {
	if (index == n) {
		solved = true;
		lexfirst = lexcmp(build);
	// generate permutations, and prune seen numbers to reduce search space
	} else {
		int ladd = build[index - 1] - d[index - 1], hadd = build[index - 1] + d[index - 1];
		if (ladd >= 0 && ladd < n) {
			if (!visited[ladd]) {
				build[index] = ladd;
				visited[ladd] = true;
				solve(index + 1);
				visited[ladd] = false;
			}
		}
		if (hadd >= 0 && hadd < n) {
			if (!visited[hadd]) {
				build[index] = hadd;
				visited[hadd] = true;
				solve(index + 1);
				visited[hadd] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		solved = false;
		d.resize(n);
		lexfirst.resize(n);
		for (int j = 0; j < n; j++) {
			lexfirst[j] = 100;
		}
		build.resize(n);
		visited.resize(n);
		for (int j = 0; j < n - 1; j++) cin >> d[j];
		for (int j = 0; j < n; j++) {
			build[0] = j;
			visited[j] = true;
			solve(1);
			visited[j] = false;
		}
		if (!solved) {
			cout << "impossible";
		} else {
			for (int j = 0; j < n; j++) {
				cout << lexfirst[j] << (j < n - 1 ? " " : "");
			}
		}
		cout << "\n";
	}

	return 0;
}
