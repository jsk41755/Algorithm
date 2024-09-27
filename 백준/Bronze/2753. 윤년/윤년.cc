#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;

	if (num % 4 == 0 && (num % 100 != 0 || num % 400 == 0)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}