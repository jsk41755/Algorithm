#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> answer;
vector<vector <int>> A;
vector<int> visited;

void BFS(int node) {
	queue<int> que;
	que.push(node);

	visited[node]++;

	while (!que.empty()) {
		int now_node = que.front();
		que.pop();

		for (int i : A[now_node]) {
			if (visited[i] == -1) {
				visited[i] = visited[now_node] + 1;
				que.push(i);
			}
		}
	}
}

int main() {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	A.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		visited[i] = -1;
	}

	BFS(X);

	for (int i = 0; i <= N; i++) {
		if (visited[i] == K) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) {
		cout << "-1" << "\n";
	}
	else {
		sort(answer.begin(), answer.end());
		for (int i : answer) {
			cout << i << "\n";
		}
	}

}