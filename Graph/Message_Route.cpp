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
int par[100001];
vector<int>arr[100001];
int dist[100001];

int main() {
	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);

	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		dist[i] = INT_MAX;
	}
	queue<int>q;
	q.push(1);
	bool  visited[n + 1] = {0};
	visited[1] = true;
	dist[1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		//visited[x] = true;
		for (auto u : arr[x] ) {
			if (!visited[u]) {
				q.push(u);
				visited[u] = true;
				par[u] = x;
				dist[u] = 1 + dist[x];
			}
		}
	}
	if (dist[n] == INT_MAX) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << dist[n] + 1 << endl;
	vector<int>ans;
	while (n != 1) {
		ans.push_back(n);
		n = par[n];
	}
	ans.push_back(1);
	reverse(ans.begin(), ans.end());
	for (auto u : ans) {
		cout << u << " ";
	}




}