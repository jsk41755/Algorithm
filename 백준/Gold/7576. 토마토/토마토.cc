#include<iostream>
#include<queue>

using namespace std;

int m, n;
int a[1001][1001];
int d[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;

bool isGone = false;

queue<pair<int, int>> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push({ i, j });
				d[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ax = x + dx[i];
			int ay = y + dy[i];

			if (ax >= 0 && ax < n && ay >= 0 && ay < m && a[ax][ay] == 0 && d[ax][ay] == -1) {
				q.push({ ax, ay });
				d[ax][ay] = d[x][y] + 1;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt < d[i][j]) {
				cnt = d[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && d[i][j] == -1) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;
}