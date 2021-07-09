#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
vector<int>arr[100001];
void dfs(int node, bool *visited) {
	visited[node] = true;
	for (auto u : arr[node]) {
		if (!visited[u]) {
			dfs(u, visited);
		}
	}
}

int main() {
	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<int>v;
	bool visited[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, visited);
			v.push_back(i);
		}
	}

	cout << int(v.size()) - 1 << endl;
	int x = v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << x << " " << v[i] << endl;
	}

}