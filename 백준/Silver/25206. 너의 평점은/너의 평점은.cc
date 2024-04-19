#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float a = 0;
	int cnt = 1;
	float ans = 0;

	for (int i = 0; i < 20; i++) {
		string s;
		getline(cin, s);

		if (s[s.size() - 1] == 'P') continue;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				string sol;
				sol += s[j + 5];
				ans = ans + (s[j + 1] - '0');

				if (sol[0] == 'A' || sol[0] == 'B' || sol[0] == 'C' || sol[0] == 'D') {
					sol += s[j + 6];
				}
				else {
					break;
				}
				
				if (sol == "A+") a = a + ((s[j + 1] - '0') * 4.5);
				if (sol == "A0") a = a + ((s[j + 1] - '0') * 4.0);
				if (sol == "B+") a = a + ((s[j + 1] - '0') * 3.5);
				if (sol == "B0") a = a + ((s[j + 1] - '0') * 3.0);
				if (sol == "C+") a = a + ((s[j + 1] - '0') * 2.5);
				if (sol == "C0") a = a + ((s[j + 1] - '0') * 2.0);
				if (sol == "D+") a = a + ((s[j + 1] - '0') * 1.5);
				if (sol == "D0") a = a + ((s[j + 1] - '0') * 1.0);

				break;
			}
		}
	}

	cout << a / ans;
	return 0;
}