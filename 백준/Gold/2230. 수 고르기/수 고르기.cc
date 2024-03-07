#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int a[1000001];
int mn = 2000000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int en = 0;

	for (int st = 0; st < n - 1; st++) {
		while (en < n && a[en] - a[st] < m) en++;
		if (en == n) break;
		mn = min(mn, a[en] - a[st]);
	}
	cout << mn;
}