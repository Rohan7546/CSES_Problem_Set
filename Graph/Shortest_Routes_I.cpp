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
#define pii pair<ll,ll>
const ll INF = 1e18;

vector<pii>arr[200002];
void dijkstra(ll s, ll n, vector<ll>& d) {
	d.assign(n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>>q;
	q.push({0, 1});
	d[1] = 0;
	while (!q.empty()) {
		ll v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (d_v != d[v])continue;
		for (auto u : arr[v]) {
			ll to = u.first;
			ll len = u.second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}
}



int main() {
	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		arr[x].push_back({y, z});

	}
	vector<ll>d;
	dijkstra(1, n, d);
	int i = 0;
	for (auto u : d) {
		if (i > 0)cout << u << " ";
		i++;
	}
}