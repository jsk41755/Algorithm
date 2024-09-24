#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	int dp[1001];
	dp[0] = 1;
	int cnt = 1;
	
	for (int i = 1; i < n; i++) {
		int num = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				num = max(num, dp[j]);
			}
		}
		dp[i] = num + 1;
		cnt = max(cnt, dp[i]);
	}

	cout << cnt;

	return 0;
}