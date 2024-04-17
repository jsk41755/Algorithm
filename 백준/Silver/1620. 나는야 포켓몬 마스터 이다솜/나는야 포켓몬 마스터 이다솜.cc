#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	map<string, int>map1;

	map<int, string>map2;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		map1.insert({ a, i });
		map2.insert({ i, a });
	}

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		if (a[0] - '0' < 10) {
			int num = 0;
			for (int j = 0; j < a.size(); j++) {
				num *= 10;
				num = num + (a[j] -'0');
			}
			cout << map2[num-1] << "\n";
		}
		else {
			cout << map1[a]+1 << "\n";
		}
	}

	return 0;
}