#include<iostream>

using namespace std;

int arr[15][15];
int n, m;
int nMax = 0;
int num = 0;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		nMax = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		num = 0;

		for (int i = 0; i <= n-m; i++) {
			for (int j = 0; j <= n-m; j++) {
				num = 0;
				for (int k = i; k < i+m; k++) {
					for (int q = j; q < j+m; q++) {
						num += arr[k][q];
					}
				}
				nMax = max(nMax, num);
			}
		}

		cout << "#" << test_case << " " << nMax << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}