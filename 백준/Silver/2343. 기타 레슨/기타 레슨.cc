#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long sum = 0;
	int l = 0, r = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		l = max(l, arr[i]);
	}

	r = sum;

	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;
		long long tmp = 0;

		for (int i = 0; i < n; i++) {
			if (tmp + arr[i] > mid) {
				tmp = 0;
				cnt++;
			}
			tmp += arr[i];
		}
		if (tmp != 0) {
			cnt ++;
		}

		if (cnt <= m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}

	}

	cout << l;

	return 0;
}