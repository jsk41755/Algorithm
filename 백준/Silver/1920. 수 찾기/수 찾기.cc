#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	map<int, int> map;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		map[num]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;

		cin >> num;

		if (map[num] == 0) cout << "0" << "\n";
		else cout << "1" << '\n';
	}




	return 0;
}