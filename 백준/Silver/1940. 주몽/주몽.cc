#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int start = 0;
	int end = A.size() - 1;
	int count = 0;

	while (start < end) {
		if (A[start] + A[end] < M) {
			start++;
		}
		else if (A[start] + A[end] > M) {
			end--;
		}
		else {
			count++;
			start++;
			end--;
		}
	}
	cout << count << endl;
}