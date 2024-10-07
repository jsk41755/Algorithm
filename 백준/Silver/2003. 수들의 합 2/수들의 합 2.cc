#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[91];

long long ans[10002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[10001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 1; i <= n; i++) {
		ans[i] += arr[i - 1] + ans[i-1];
	}
	int cnt = 0;

	int l = 0, r = 1;

	while (r<=n) {
		if (ans[r] - ans[l] == m) {
			cnt++;
			l++;
			r++;
		}
		else if (ans[r] - ans[l] > m) {
			l++;
		}
		else if (ans[r] - ans[l] < m) {
			r++;
		}
	}

	cout << cnt;

	return 0;
}