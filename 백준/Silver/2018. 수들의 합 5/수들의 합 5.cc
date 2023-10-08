#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	int count = 1;
	int start = 1;
	int end = 1;
	int sum = 1;

	while (end != N) {
		if (sum == N) {
			count++;
			end++;
			sum += end;
		}
		else if (sum > N) {
			sum -= start;
			start++;
		}
		else {
			end++;
			sum += end;
		}
	}

	cout << count << endl;
}