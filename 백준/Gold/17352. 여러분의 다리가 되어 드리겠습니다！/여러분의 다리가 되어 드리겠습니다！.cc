#include<iostream>
#include<vector>

using namespace std;

int n;
int x, y;

vector<int> a;

int find(int i) {
	if (a[i] == i) return i;
	else return a[i] = find(a[i]);
}

void Union(int x, int y) {
	int aRoot = find(x);
	int bRoot = find(y);

	a[aRoot] = bRoot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	a.resize(n+1);

	for (int i = 0; i <= n; i++) {
		a[i] = i;
	}

	for (int i = 0; i < n-2; i++) {

		cin >> x >> y;

		Union(x, y);
	}

	for (int i = 1; i <= n-1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (find(i) != find(j)) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
}