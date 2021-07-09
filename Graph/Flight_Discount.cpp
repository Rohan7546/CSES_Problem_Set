#include<bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define ll long long
const ll INF = 1e17;
ll dist[100001];
ll distn[100001];
bool visi[100001];
vector<pair<ll, ll>>arr[100001];
vector<pair<ll, ll>>arrn[100001];
void dijkstra(ll s) {
	dist[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>>q;
	q.push({0, s});
	while (!q.empty()) {
		ll u = q.top().second;
		ll d = q.top().first;
		//if (dist[u] != d)continue;
		q.pop();
		if (visi[u])continue;
		visi[u] = true;
		for (auto i : arr[u]) {
			ll x = i.first;
			ll d = i.second;
			if (dist[x] > dist[u] + d) {
				dist[x] = dist[u] + d;
				q.push({dist[x], x});
			}
		}
	}
}

void dijkstran(ll s) {
	distn[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>>q;
	q.push({0, s});
	while (!q.empty()) {
		ll u = q.top().second;
		ll d = q.top().first;
		//	if (distn[u] != d)continue;
		q.pop();

		if (visi[u])continue;
		visi[u] = true;
		for (auto i : arrn[u]) {
			ll x = i.first;
			ll d = i.second;
			if (distn[x] > distn[u] + d) {
				distn[x] = distn[u] + d;
				q.push({distn[x], x});
			}
		}
	}
}

int main() {
	ll  n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		arr[x].push_back({y, z});
		arrn[y].push_back({x, z});
	}

	for (ll i = 0; i <= n; i++) {
		dist[i] = INF;
		distn[i] = INF;
	}

	dijkstra(1); for (int i = 0; i <= n; i++) {
		visi[i] = false;
	}
	dijkstran(n);
	ll cost = dist[n];
	for (ll i = 1; i <= n; i++) {
		for (auto u : arr[i]) {
			ll x = u.first;
			ll y = u.second;
			cost = min(cost, dist[i] + distn[x] + y / 2);
		}
	}
	cout << cost << endl;

}