#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int arr[1001][1001];
int v[1001][1001];
bool isVisit[1001][1001];

int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) q.push({ i, j });
		}
	}

	isVisit[q.front().first][q.front().second] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ay = y + dy[i];
			int ax = x + dx[i];

			if (ax >= 0 && ax < m && ay >= 0 && ay < n) {
				if (!isVisit[ay][ax] && arr[ay][ax] == 1) {
					v[ay][ax] = v[y][x] + 1;
					isVisit[ay][ax] = true;
					q.push({ ay, ax });
				}
			}
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!isVisit[i][j] && arr[i][j] == 1) v[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}



	return 0;
}