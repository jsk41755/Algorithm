#include<iostream>

using namespace std;

int arr[9][9];
bool hor[10];
bool ver[10];
bool matrix[10];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		bool sol = false;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 9; i++) {
			
			for (int j = 1; j < 10; j++) {
				hor[j] = false;
			}

			for (int j = 0; j < 9; j++) {
				if (!hor[arr[i][j]]) hor[arr[i][j]] = true;
				else {
					sol = true;
				}
			}
		}


		for (int i = 0; i < 9; i++) {

			for (int j = 1; j < 10; j++) {
				ver[j] = false;
			}

			for (int j = 0; j < 9; j++) {
				if (!ver[arr[j][i]]) ver[arr[j][i]] = true;
				else {
					sol = true;
				}
			}
		}


		for (int i = 0; i < 9; i++) {
			for (int j = 1; j < 10; j++) {
				matrix[j] = false;
			}


			for (int j = i; j < i + 3; j++) {
				for (int k = i; k < i + 3; k++) {
					if (!matrix[arr[j][k]]) matrix[arr[j][k]] = true;
					else {
						sol = true;
					}
				}
			}

			i += 2;
		}

		if (sol) {
			cout << "#" << test_case << " " << 0 << "\n";
		}
		else {
			cout << "#" << test_case << " " << 1 << "\n";
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}