#include<iostream>
#include<vector>

using namespace std;

int arr[1001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> arr[i][0];
	}

	arr[0][1] = arr[0][0];


	for (int i = 1; i < a; i++) {
		int k = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i][0] > arr[j][0]) {
				k = max(k, arr[j][1]);
			}
		}

		if (k > 0) {
			arr[i][1] = arr[i][0] + k;
		}
		else {
			arr[i][1] = arr[i][0];
		}
		
	}

	int t = 0;
	for (int i = 0; i < a; i++) {
		t = max(t, arr[i][1]);
	}

	cout << t;

	return 0;
}