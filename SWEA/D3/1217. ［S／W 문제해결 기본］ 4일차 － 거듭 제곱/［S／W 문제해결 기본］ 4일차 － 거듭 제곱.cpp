#include<iostream>

using namespace std;

int rec(int a, int cnt, int b, int sol) {
	if (cnt == b + 1) {
		return sol;
	}

	rec(a, cnt + 1, b, sol * a);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//cin >> T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;

		int a, b;

		cin >> a >> b;

		int res = rec(a, 1, b, 1);

		cout << "#" << test_case << " " << res << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}