#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long dp[101][10];		// dp[i][j] : i자리 수 계단 수 중에 맨 끝이 j인 수의 개수
const long long MOD = 1000000000;

long long solution()
{
	// 1자리 계단수는 1 ~ 9 이므로 1 ~ 9로 끝나는 수의 개수는 각 1개씩
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		// 맨 끝이 0인 i자리 수의 개수 = 이전 자리(i - 1) 수 중 1로 끝나는 수의 개수
		dp[i][0] = dp[i - 1][1] % MOD;
		// 맨 끝이 j(1 ~ 8)인 i자리 수의 개수 = 이전 자리(i - 1) 수 중 (j - 1)로 끝나는 수의 개수 + (j + 1)로 끝나는 수의 개수
		for (int j = 1; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		// 맨 끝이 9인 i자리 수의 개수 = 이전 자리(i - 1) 수 중 8로 끝나는 수의 개수
		dp[i][9] = dp[i - 1][8] % MOD;
	}

	long long maxValue = 0;
	for (int i = 0; i <= 9; i++)
		maxValue = (maxValue + dp[n][i]) % MOD;

	return maxValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << solution();
}