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
bool visited[100001];


bool flag = true;

void dfs(int node, int p) {
	visited[node] = true;
	par[node] = p;
	for (auto u : arr[node]) {
		if (par[u] == par[node]) {
			flag = false;
		}
		if (!visited[u]) {
			dfs(u, p ^ 3);
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
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	if (!flag) {
		cout << "IMPOSSIBLE";
	}
	else {
		for (int i = 1; i <= n; i++) {
			cout << par[i] << " ";
		}
	}


}