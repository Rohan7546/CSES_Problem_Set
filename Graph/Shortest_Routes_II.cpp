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


int main() {
	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	ll n, m, q;
	cin >> n >> m >> q;
	ll dist[n + 1][n + 1];
	for (ll i = 0; i < n + 1; i++) {
		for (ll j = 0; j < n + 1; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = LONG_MAX;
		}
	}


	for (ll i = 0; i < m; i++) {
		ll f, d, w;
		cin >> f >> d >> w;
		dist[f][d] = min(dist[f][d], w);
		dist[d][f] = min(dist[f][d], w);
	}


	for (ll k = 1; k <= n; k++) {

		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (dist[i][k] != LONG_MAX && dist[k][j] != LONG_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}





	while (q--) {
		ll a, b;
		cin >> a >> b;
		if (dist[a][b] == LONG_MAX) {
			cout << -1 << "\n";
		}
		else
			cout << dist[a][b] << "\n";
	}

}