#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int mx = -1;
	int mi = 2000000001;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		mi = min(mi, arr[i]);
	}

	sort(arr, arr + n);

	int l=0, r = mx;

	int cnt = 0;

	while (l <= r) {
		int half = (r + l) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			int tmp = arr[i] - half;
			if (tmp > 0) sum += tmp;
		}

		if (sum >= m) {
			if (cnt < half) {
				cnt = half;
			}
			l = half + 1;
		}
		else {
			r = half - 1;
		}
	}

	cout << cnt;


	return 0;
}