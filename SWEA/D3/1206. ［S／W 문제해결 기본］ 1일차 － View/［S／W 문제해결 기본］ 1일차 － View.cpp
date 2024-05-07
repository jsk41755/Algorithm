#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int arr[1001];
		int sol = 0;
		int count = 0;

		cin >> count;

		for (int i = 0; i < count; i++) {
			cin >> arr[i];
		}

		for (int i = 2; i < count-2; i++) {
			int lMax = 300;
			int rMax = 300;
			int total = -1;

			lMax = max(arr[i - 2], arr[i - 1]);
			rMax = max(arr[i + 1], arr[i + 2]);

			if (arr[i] - lMax > 0 && arr[i] - rMax > 0) {
				total = max(lMax, rMax);
				sol = sol + (arr[i] - total);
			}
		}

		cout << "#" << test_case << " " << sol << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}