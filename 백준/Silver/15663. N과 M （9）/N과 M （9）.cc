#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int n, m;

vector<bool> isCheck;
vector<int> answer;

void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		int mem = 0;
		for (int i = 0; i < n; i++) {
			if (isCheck[i]) {
				continue;
			}
			else if (mem != v[i]) {
				isCheck[i] = true;
				answer[cnt] = v[i];
				mem = v[i];
				func(cnt + 1);
				isCheck[i] = false;
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	isCheck.resize(10001, false);
	answer.resize(10001, 0);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	func(0);

	return 0;
}