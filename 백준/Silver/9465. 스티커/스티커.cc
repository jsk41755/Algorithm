#include <iostream>
#include <vector>
#include <algorithm>

int t, n;
long long arr[2][100002];
long long  dp[2][100002];

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		int cnt = 0;

		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + arr[1][j];
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";

	}

	


	return 0;
}