#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int num;
		cin >> num;
		cin.ignore();
		map<string, int> m;

		if (num == 0) {
			cout << 0 << "\n";
			continue;
		}

		for (int i = 0; i < num; i++) {
			string s, sn;
			getline(cin, s);

			bool flag = false;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == ' ') flag = true;

				if (flag) sn += s[j];
			}

			m[sn]++;
		}

		int ans = 1;

		for (auto itr = m.begin(); itr != m.end(); itr++) {
			ans *= (itr->second + 1);
		}

		ans -= 1;
		cout << ans << "\n";
	}

	return 0;
}