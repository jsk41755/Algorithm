#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;

	cin >> n >> k;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	cout << "<";

	for (int j = 0; j < n; j++) {
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
			break;
		}

		for (int i = 0; i < k-1; i++) {
			int top = q.front();
			q.pop();
			q.push(top);
		}

		cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}