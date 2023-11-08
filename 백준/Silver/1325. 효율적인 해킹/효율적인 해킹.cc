#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;
vector<int> answer;
void BFS(int node);

int main() {
	int N, M;

	cin >> N >> M;

	A.resize(N+1);
	answer.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visited.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}
	
	int maxVal = -1;

	for (int i = 1; i <= N; i++) {
		if (maxVal < answer[i]) {
			maxVal = answer[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (answer[i] == maxVal) {
			cout << i << " ";
		}
	}
}

void BFS(int node) {
	queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty()) {
		int check = queue.front();
		queue.pop();
		for (int a : A[check]) {
			if (!visited[a]) {
				visited[a] = true;
				answer[a]++;
				queue.push(a);
			}
		}
	}
}