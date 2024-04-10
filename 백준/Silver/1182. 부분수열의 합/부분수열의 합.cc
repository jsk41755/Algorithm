#include<iostream>
#include<vector>

using namespace std;

int n, s;
vector<int> a;
int cnt = 0;

void dp(int cur, int sum) {
	if (cur == n) {
		if (sum == s) {
			cnt++;
		}
		return;
	}

	dp(cur + 1, sum);
	dp(cur + 1, sum + a[cur]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	dp(0, 0);
	if (s == 0) cnt--;

	cout << cnt;
}