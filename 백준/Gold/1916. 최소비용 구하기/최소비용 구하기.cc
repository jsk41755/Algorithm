#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int v, e, st, en;
vector<pair<int, int>> adj[1005];
const int INF = 987654321;
int d[1005];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> v >> e;

    fill(d, d + v + 1, INF);

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> st >> en;

    d[st] = 0;
    pq.push({ d[st], st });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }

    if (d[en] == INF) cout << -1 << "\n";
    else cout << d[en];


    return 0;
}
