#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

string arr[601];

bool isVisit[601][601];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int x, y;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'I') {
				x = j;
				y = i;
			}

			if (arr[i][j] == 'X') {
				isVisit[i][j] = true;
			}
		}
	}

	q.push({ y, x });
	isVisit[y][x] = true;
	int cnt = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ay = a + dy[i];
			int ax = b + dx[i];

			if (ax >= 0 && ax < m && ay >= 0 && ay < n) {
				if (!isVisit[ay][ax] && arr[ay][ax] != 'X') {
					isVisit[ay][ax] = true;
					q.push({ ay,ax });
					if (arr[ay][ax] == 'P') cnt++;
				}
			}
		}
	}

	if (cnt == 0) {
		cout << "TT";
		return 0;
	}

	cout << cnt;

	return 0;
}