#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define X first
#define Y second

int v, e, st, en;

vector<pair<int, int>> adj[1005];
const int INF = 1e9 + 10;
int d[1005];
int pre[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	fill(d, d + v + 1, INF);

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	cin >> st >> en;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
			pre[nxt.Y] = cur.Y;
		}
	}

	cout << d[en] << "\n";
	int cur = en;
	vector<int> ve;
	

	while (cur != st) {
		ve.push_back(cur);
		cur = pre[cur];
	}
	ve.push_back(cur);

	cout << ve.size() << "\n";
	reverse(ve.begin(), ve.end());

	for (auto t : ve) {
		cout << t << " ";
	}


	return 0;
}