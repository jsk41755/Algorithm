#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int l = 0;
	int r = n - 1;

	int x;

	cin >> x;

	int cnt = 0;

	while (l < r) {
		int sum = v[l] + v[r];

		if (sum > x) {
			r--;
		}
		else if (sum < x) {
			l++;
		}
		else {
			cnt++;
			l++;
			r--;
		}
	}

	cout << cnt;

	return 0;
}