#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> number;
vector<char> cal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] != '-') {
			cal.push_back('+');
		}

		if (s[i] == '+') {
			cal.push_back('+');
			continue;
		}

		if (s[i] == '-') {
			cal.push_back('-');
			continue;
		}

		int num = 0;
		while (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			num *= 10;
			num = num + (s[i] - '0');
			i++;
		}

		if (num != 0) {
			i--;
			number.push_back(num);
		}
	}

	int temp = 0;
	int sum = 0;

	for (int i = 0; i < number.size(); i++) {
		if (cal[i] == '-') {
			while (i < number.size()) {
				sum -= number[i];
				i++;
			}
			break;
		}
		else {
			sum += number[i];
		}
	}

	cout << sum;

	return 0;
}