#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num = i;
		int cnt = 0;

		while (num > 0) {
			int nnum = num % 10;

			if (nnum == 3 || nnum == 6 || nnum == 9) {
				cout << "-";
				cnt++;
			}

			num /= 10;
		}

		if (cnt == 0) {
			cout << i;
		}

		cout << " ";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}