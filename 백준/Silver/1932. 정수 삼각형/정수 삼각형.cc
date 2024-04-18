#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int arr[501][501] = { 0, };
int sol[501][501] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i][j] + max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		answer = max(answer, arr[n][i]);
	}

	cout << answer;

	return 0;
}