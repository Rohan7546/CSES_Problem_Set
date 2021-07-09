#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const ll INF = 1e17;
const ll NINF = -1e17;


class edge {
public :
	ll v1, v2, w;
};
ll dist[100001];
void bellmanford(ll n, ll e, edge ** edg) {

	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < e; j++) {
			ll u = edg[j]->v1;
			ll v = edg[j]->v2;
			ll w = edg[j]->w;
			if (dist[u] != INF && (dist[v] > dist[u] + w)) {
				dist[v] = dist[u] + w;
			}
			//dist[v] = max(dist[v], NINF);
		}
	}

	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < e; j++) {
			ll u = edg[j]->v1;
			ll v = edg[j]->v2;
			ll w = edg[j]->w;
			if (dist[u] == INF)continue;
			//	dist[v] = max(dist[v], NINF);

			if ( (dist[v] > dist[u] + w)) {
				dist[v] = NINF;
			}
		}
	}







}


int main() {
//	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	ll n, e; cin >> n >> e;
	edge **edg = new edge*[e];
	for (ll i = 0; i < e; i++) {
		edg[i] = new edge[3];
		//cin >> edg[i]->v1 >> edg[i] >> v2 >> edg[i] >> w;
		ll x, y, z;
		cin >> x >> y >> z;
		edg[i]->v1 = x;
		edg[i]->v2 = y;
		edg[i]->w = -z;

	}
	for (ll i = 0; i < 100001; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	bellmanford(n, e, edg);


	if (dist[n] == NINF) {
		cout << -1 << "\n";
	}
	else {
		cout << dist[n]*(-1);
	}






	for (ll i = 0; i < e; i++) {
		delete [] edg[i];
	}

}