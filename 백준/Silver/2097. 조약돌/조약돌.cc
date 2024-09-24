#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (1 <= n && n <= 4) cout << 4;
	else {
		int num = round(sqrt(n));

		if (num * num >= n) cout << (num - 1) * 4;
		else cout << ((num - 1) * 2) + (num * 2);
	}

	return 0;
}