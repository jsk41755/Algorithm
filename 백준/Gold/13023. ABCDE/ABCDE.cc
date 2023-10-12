#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> A[2001];
vector<bool> visited;
bool arrive = false;

void dfs(int node, int deps) {
	if (deps == 5 || arrive) {
		arrive = true;
		return;
	}
	visited[node] = true;
	
	for (int i = 0; i < A[node].size(); i++) {
		if (!visited[A[node][i]]) {
			dfs(A[node][i], deps+1);
		}
	}

	visited[node] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	visited.resize(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		int deps = 1;
		dfs(i, deps);
		if (arrive) {
			break;
		}
	}

	if (arrive) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}