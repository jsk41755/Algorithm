#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a;
	string b;


	cin >> a;
	cin >> b;
	int c = -1;
	int cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				arr[i + 1][j + 1] = arr[i][j] + 1;
				cnt = max(cnt, arr[i + 1][j + 1]);
			}
			else {
				arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);
				cnt = max(cnt, arr[i + 1][j + 1]);
			}
		}
	}

	cout << cnt;

	return 0;
}