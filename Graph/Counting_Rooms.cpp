#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 100011;

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
//------------------------------------------------------------

int r, c;
bool visited[2501][2501];
char a[2501][2501];



bool isvalid(int i, int j) {
	return (i >= 0 && i < r && j >= 0 && j < c && a[i][j] != '#');
}

void dfs(int i, int j, int n, int m) {
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	int xc[4] = { -1, 0, 0, 1};
	int yc[4] = {0, 1, -1, 0};
	for (int k = 0; k < 4; k++) {
		int x = xc[k] + i;
		int y = yc[k] + j;
		if (!isvalid(x, y)) {
			continue;
		}

		dfs(x, y, n, m);
	}
}





int main() {
	debugMode();
	ios_base:: sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		//string s; cin >> s;
		for (int j = 0; j < c; j++) {

			cin >> a[i][j];
			//a[i][j] = s[j];


		}
	}

	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] && a[i][j] == '.') {
				dfs(i, j, r, c);
				cnt++;
			}
		}
	}


	cout << cnt << endl;












}