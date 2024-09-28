#include<iostream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;
	cin.ignore();

	map<string, string> ma;

	for (int i = 0; i < n; i++) {
		string s, d, a;
		getline(cin, s);

		int cnt = 0;
		while (s[cnt] != ' ') {
			d += s[cnt];
			cnt++;
		}

		for (int i = cnt + 1; i < s.size(); i++) {
			a += s[i];
		}

		ma[d] = a;
	}

	for (int i = 0; i < m; i++) {
		string s;

		cin >> s;

		cout << ma[s] << "\n";
	}

	return 0;
}