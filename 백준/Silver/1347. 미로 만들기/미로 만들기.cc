#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<char> q;
char arr[101][101];
queue<pair<int, int>> a;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
char arrow[4] = { 'v', '<', '^', '>' };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		q.push(s[i]);
	}

	int sw = 999, ew = -1, sh = 999, eh= -1;
	int current = 4;

	a.push({ 50, 50 });
	arr[50][50] = '.';

	while (!q.empty()) {
		char cmd = q.front();
		q.pop();

		if (cmd == 'L') {
			current = current >> 1;
			if (current <= 0) current = 8;
		}

		if (cmd == 'R') {
			current = current << 1;
			if (current > 8) current = 1;
		}

		if (cmd == 'F') {
			int y = a.front().first;
			int x = a.front().second;
			a.pop();

			if (current == 1) {
				int ny = y + dy[3];
				int nx = x + dx[3];
				arr[ny][nx] = '.';
				a.push({ ny, nx });
			}
			if (current == 2) {
				int ny = y + dy[0];
				int nx = x + dx[0];
				arr[ny][nx] = '.';
				a.push({ ny, nx });
			}
			if (current == 4) {
				int ny = y + dy[2];
				int nx = x + dx[2];
				arr[ny][nx] = '.';
				a.push({ ny, nx });
			}
			if (current == 8) {
				int ny = y + dy[1];
				int nx = x + dx[1];
				arr[ny][nx] = '.';
				a.push({ ny, nx });
			}

		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == '.' && sw > j) {
				sw = j;
			}
			if (arr[i][j] == '.' && ew < j) {
				ew = j;
			}
			if (arr[i][j] == '.' && sh > i) {
				sh = i;
			}
			if (arr[i][j] == '.' && eh < i) {
				eh = i;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] != '.') arr[i][j] = '#';
		}
	}

	int wRange = ew - sw + 1;
	int hRange = eh - sh + 1;

	vector<vector<char>> v(hRange, vector<char>(wRange));

	for (int i = 0; i < hRange; i++) {
		for (int j = 0; j < wRange; j++) {
			v[i][j] = arr[i + sh][j + sw];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}

	return 0;
}