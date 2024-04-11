#include<iostream>
#include<vector>

using namespace std;

int t, m, n, k;
int arr[51][51];


int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
	if (arr[y][x] == 0) return;

	arr[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax >= 0 && ax < m && ay >= 0 && ay < n) {
			dfs(ay, ax);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		int cnt = 0;

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			int x, y;

			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int l = 0; l < n; l++) {
			for (int w = 0; w < m; w++) {
				if (arr[l][w] == 1) {
					cnt++;
					dfs(l, w);
				}
			}
		}

		cout << cnt << "\n";

		for (int l = 0; l < n; l++) {
			for (int w = 0; w < m; w++) {
				arr[l][w] = 0;
			}
		}

		cnt = 0;
	}
}