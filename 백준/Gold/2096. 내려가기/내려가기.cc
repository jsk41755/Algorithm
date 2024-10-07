#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int b1 = 0, b2 = 0, b3 = 0;
int c1 = 0, c2 = 0, c3 = 0;
int t1 = 0, t2 = 0, t3 = 0;
int v[100001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}

		t1 = max(b1, b2) + v[i][0];
		t2 = max(b1, max(b2, b3)) + v[i][1];
		t3 = max(b2, b3) + v[i][2];

		b1 = t1;
		b2 = t2;
		b3 = t3;

		t1 = min(c1, c2) + v[i][0];
		t2 = min(c1, min(c2, c3)) + v[i][1];
		t3 = min(c2, c3) + v[i][2];
		c1 = t1;
		c2 = t2;
		c3 = t3;
	}
	int bMax = max(b1, max(b2, b3));
	int cMin = min(c1, min(c2, c3));


	cout << bMax << " " << cMin;

	return 0;
}