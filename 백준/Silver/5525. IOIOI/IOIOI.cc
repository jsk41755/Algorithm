#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	bool flag= false;
	
	string s;
	int cnt = 0;
	int ans = 0;
	cin >> s;

	vector<int> v;

	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') v.push_back(i);
	}

	for (auto a : v) {
		for (int i = a; i < a + n + n + 1 && i<m; i++) {
			if (s[i] == 'I' && !flag) {
				cnt++;
				flag = true;
			}
			else if (s[i] == 'O' && flag) {
				cnt++;
				flag = false;
			}
			else {
				break;
			}
		}

		if (cnt == n + n + 1) ans++;
		cnt = 0;
		flag = false;
	}

	cout << ans;


	return 0;
}