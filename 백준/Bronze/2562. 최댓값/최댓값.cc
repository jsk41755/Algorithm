#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[9];

	int num = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		num = max(num, arr[i]);
	}

	for (int i = 0; i < 9; i++) {
		if (num == arr[i]) {
			cout << num << "\n";
			cout << i + 1;
		}
	}

	return 0;
}