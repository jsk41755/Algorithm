#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;

	cin >> n;
	int cnt = 0;
	int num = 0;

	while (cnt != n) {
		num++;

		int temp = num;

		while (temp >= 666) {
			if (temp % 1000 == 666) {
				cnt++;

				break;
			}
			else {
				temp /= 10;
			}
		}

	}

	cout << num;

	return 0;
}