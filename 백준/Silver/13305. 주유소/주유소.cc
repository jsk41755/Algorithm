#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N;

	cin >> N;

	vector<long long> dist(N - 1), cost(N);
	long long result = 0, now;

	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}

	now = cost[0];
	result = now * dist[0];

	for (int i = 1; i < N - 1; i++) {
		if (cost[i] < now) {
			now = cost[i];
			result += now * dist[i];
		}
		else {
			result += now * dist[i];
		}
	}

	cout << result << "\n";



	return 0;
}