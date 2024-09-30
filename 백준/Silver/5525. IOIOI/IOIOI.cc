#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	string s;
	int cnt = 0;
	int ans = 0;
	cin >> s;

	bool flag = false;

	if (s[0] == 'I') {
		arr[0] = 1;
		flag = true;
	}
	
	for (int i = 1; i < m; i++) {
		if (!flag && s[i] == 'I') {
			arr[i] = arr[i - 1] + 1;
			flag = true;
		}
		else if (flag && s[i] == 'O') {
			arr[i] = arr[i - 1] + 1;
			flag = false;
		}
		else if(s[i] == 'I' && flag) {
			arr[i] = 1;
		}
		else {
			arr[i] = 0;
			flag = false;
		}
	}

	for (int i = 0; i < m - n - n; i++) {
		if (arr[i] % 2 == 1 && arr[i + n + n] - arr[i] == n + n) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}