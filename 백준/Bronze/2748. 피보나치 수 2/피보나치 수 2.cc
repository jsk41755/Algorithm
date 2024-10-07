#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[91];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];

	return 0;
}