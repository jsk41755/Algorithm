#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// BFS를 이용해 각 사람 간의 최소 거리를 계산하는 함수
int bfs(int start, const vector<vector<int>>& graph, int N) {
    vector<int> dist(N + 1, INF); // 각 사람까지의 거리를 INF로 초기화
    queue<int> q;

    dist[start] = 0; // 시작점의 거리는 0
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] == INF) { // 아직 방문하지 않은 경우
                dist[next] = dist[cur] + 1; // 거리를 1 증가시킴
                q.push(next);
            }
        }
    }

    // 모든 사람과의 거리 합계를 반환
    int total_dist = 0;
    for (int i = 1; i <= N; i++) {
        total_dist += dist[i];
    }
    return total_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; // N: 사람 수, M: 친구 관계 수
    cin >> N >> M;

    vector<vector<int>> graph(N + 1); // 친구 관계를 저장하는 그래프

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_bacon = INF;
    int result_person = 0;

    // 각 사람마다 BFS를 실행하여 케빈 베이컨 수를 계산
    for (int i = 1; i <= N; i++) {
        int bacon_number = bfs(i, graph, N);
        if (bacon_number < min_bacon) {
            min_bacon = bacon_number;
            result_person = i;
        }
    }

    // 케빈 베이컨 수가 가장 작은 사람을 출력
    cout << result_person << "\n";

    return 0;
}
