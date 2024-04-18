#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;

	cin >> n;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] % 10007 + arr[i - 2] % 10007) % 10007;
	}

	cout << arr[n];

	return 0;
}