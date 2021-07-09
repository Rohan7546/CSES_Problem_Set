#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000;

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//------------------------------------------------------------

int r, c;
int dist[2501][2501];
char a[2501][2501];
pair<pair<int, int>, char>pre[2501][2501];




bool isvalid(pair<int, int>x) {
//	return (i >= 0 && i < r && j >= 0 && j < c && a[i][j] != '#');
	return (x.first >= 0 && x.first < r && x.second >= 0 && x.second < c && a[x.first][x.second] != '#');

}







int main() {
	//debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	int ind1, ind2, ind3, ind4;
	pair<int, int>st, en;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		//string s; cin >> s;
		for (int j = 0; j < c; j++) {
			dist[i][j] = mod;
			cin >> a[i][j];
			//a[i][j] = s[j];
			if (a[i][j] == 'A') {
				st = {i, j};
			}
			else if (a[i][j] == 'B') {
				en = {i, j};
			}

		}
	}
	int xc[4] = {0, 1, 0, -1};
	int yc[4] = {1, 0, -1, 0};




//    input take
	dist[st.first][st.second] = 0;
	queue<pair<int, int>>q;
	q.push(st);
	string res = "RDLU";
//	cout<<st.first<<st.second<<en.first<<en.second;

	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int>X = {xc[i] + x.first,  yc[i] + x.second};
			if (!isvalid(X) || dist[X.first][X.second] != mod)
				continue;
			// cout<<res[i]<<" ";
			dist[X.first][X.second] = 1 + dist[x.first][x.second];
			pre[X.first][X.second] = {x, res[i]};
			q.push(X);
		}
	}

	if (dist[en.first][en.second] == mod) {
		cout << "NO\n";
		return 0;
	}
	string ans = "";
	while (en != st) {
		ans += pre[en.first][en.second].second;
		en = pre[en.first][en.second].first;
	}
	cout << "YES\n";
	cout << ans.length() << endl;
	reverse(ans.begin(), ans.end());
	cout << ans;















}