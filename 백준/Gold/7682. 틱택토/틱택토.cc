#include<iostream>
#include<string>

using namespace std;

bool checkX(char c[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (c[i][0] == 'X' && c[i][0] == c[i][1] && c[i][1] == c[i][2]) return true;
		if (c[0][i] == 'X' && c[0][i] == c[1][i] && c[1][i] == c[2][i]) return true;
	}

	if (c[0][0] == 'X' && c[1][1] == c[2][2] && c[0][0] == c[1][1]) return true;
	if (c[0][2] == 'X' && c[1][1] == c[0][2] && c[2][0] == c[1][1]) return true;

	return false;
}

bool checkO(char c[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (c[i][0] == 'O' && c[i][0] == c[i][1] && c[i][1] == c[i][2]) return true;
		if (c[0][i] == 'O' && c[0][i] == c[1][i] && c[1][i] == c[2][i]) return true;
	}

	if (c[0][0] == 'O' && c[1][1] == c[2][2] && c[0][0] == c[1][1]) return true;
	if (c[0][2] == 'O' && c[1][1] == c[0][2] && c[2][0] == c[1][1]) return true;

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;



	while (1) {
		char c[3][3];

		cin >> s;

		if (s == "end") return 0;

		int x = 0;
		int o = 0;

		for (int i = 0; i < 9; i++) {
			c[i / 3][i % 3] = s[i];

			if (c[i / 3][i % 3] == 'X') x++;
			else if(c[i / 3][i % 3] == 'O') o++;
		}

		bool isX = checkX(c);
		bool isO = checkO(c);


		if (isX && !isO && x == o + 1) cout << "valid" << "\n";
		else if (!isX && isO && x == o) cout << "valid" << "\n";
		else if (!isX && !isO && o == 4 && x == 5) cout << "valid" << "\n";
		else cout << "invalid" << "\n";
	}

	return 0;
}