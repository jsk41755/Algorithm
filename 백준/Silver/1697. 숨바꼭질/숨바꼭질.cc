#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> visited(MAX + 1, -1); // 방문 여부 및 소요 시간 저장
    queue<int> q;

    visited[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == K) {
            cout << visited[current] << '\n';
            return 0;
        }

        // 다음 위치들을 탐색
        int next_positions[] = { current - 1, current + 1, current * 2 };

        for (int next : next_positions) {
            if (next >= 0 && next <= MAX && visited[next] == -1) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }

    return 0;
}
