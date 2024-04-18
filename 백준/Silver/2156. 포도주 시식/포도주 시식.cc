#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		arr[i] = num;
	}

	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i] + arr[i - 1], max(dp[i - 2] + arr[i], dp[i-1]));
	}

	cout << dp[n];

	return 0;
}