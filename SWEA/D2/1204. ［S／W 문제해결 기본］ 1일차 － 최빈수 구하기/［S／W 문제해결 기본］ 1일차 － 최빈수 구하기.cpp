#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[1001] = { 0, };
		
		for (int i = 0; i < 1001; i++) {
			int a;
			cin >> a;
			arr[a]++;
		}

		int nMax = 0;
		int idx = 0;

		for (int i = 1; i < 1001; i++) {
			if (nMax <= arr[i]) {
				nMax = arr[i];
				idx = i;
			}
		}

		cout << "#" << test_case << " " << idx << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}