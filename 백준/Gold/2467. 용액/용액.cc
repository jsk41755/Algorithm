#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int st = 0;
	int en = n - 1;

	long long res = abs(v[st] + v[en]);
	long long resL = v[st];
	long long resR = v[en];

	while (st < en) {
		long long temp = v[st] + v[en];
		if (abs(temp) < res) {
			res = abs(temp);
			resL = v[st];
			resR = v[en];
		}

		if (temp < 0) {
			st++;
		}
		else {
			en--;
		}
	}

	cout << resL << " " << resR;
}