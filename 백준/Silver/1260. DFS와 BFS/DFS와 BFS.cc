#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> A[10001];
vector<bool> visited;
bool arrive = false;


void dfs(int node) {
	cout << node << " ";
	visited[node] = true;
	for (int i : A[node]) {
		if (!visited[i]) {
			dfs(i);
		}	
	}
}

void bfs(int node) {
	queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty()) {
		int now_node = queue.front();
		queue.pop();
		cout << now_node << " ";
		for (int i : A[now_node]) {
			if (!visited[i]) {
				visited[i] = true;
				queue.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	visited.resize(n+1);

	for (int i = 0; i < m; i++) {
		int u, q;

		cin >> u >> q;

		A[u].push_back(q);
		A[q].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(A[i].begin(), A[i].end());
	}


	dfs(v);
	cout << "\n";

	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}

	bfs(v);
}