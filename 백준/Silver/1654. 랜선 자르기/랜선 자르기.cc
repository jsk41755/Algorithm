#include<iostream>
#include<vector>

using namespace std;

int k, n;
long _max = 0;
long _min = 0;
vector<int> arr;

long binarySearch() {
	long mid = 0;

	while (_min < _max) {
		mid = (_max + _min) / 2;

		int cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt < n) {
			_max = mid;
		}
		else {
			_min = mid + 1;
		}
	}

	return _min;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;

	arr.resize(k);


	for (int i = 0; i < k; i++) {
		cin >> arr[i];

		if (_max < arr[i]) {
			_max = arr[i];
		}
	}

	_max++;

	long sol = binarySearch();

	cout << sol-1;
}