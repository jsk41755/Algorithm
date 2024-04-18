#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d;

	cin >> n >> d;

	vector<pair<long, long>> a(n+1);

	for (int i = 1; i <= n; i++) {
		int p, v;
		cin >> p >> v;
		a[i].first = p;
		a[i].second = v;
	}

	sort(a.begin() + 1, a.end());
	int l, r;
	l = r = 1;

	long long temp = 0;
	long long sol = 0;
	while (r <= n) {
		if (a[r].first - a[l].first < d) {
			temp += a[r].second;
			r++;
		}
		else {
			temp -= a[l].second;
			l++;
		}
		sol = max(sol, temp);
	}

	cout << sol;

	return 0;
}