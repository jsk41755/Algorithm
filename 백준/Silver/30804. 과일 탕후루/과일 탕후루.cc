#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	vector<int> c(10, 0);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int l = 0, r = 0;
	int distinct_fruit_count = 0;
	int result = 0;

	while (r < n) {
		if (c[v[r++]]++ == 0) {
			distinct_fruit_count++;
		}

		while (distinct_fruit_count > 2) {
			if (--c[v[l++]] == 0) {
				distinct_fruit_count--;
			}
		}

		result = max(result, r - l);
	}

	cout << result;

	return 0;
}