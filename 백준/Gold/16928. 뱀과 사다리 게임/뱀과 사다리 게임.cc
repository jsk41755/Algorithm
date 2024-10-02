#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[13][13]; // 2차원 좌표를 1차원으로 변환하기 위한 배열
vector<int> board(101, 987654321); // 최소 이동 횟수를 저장하는 배열, 초기값을 큰 값으로 설정

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; // 사다리 개수와 뱀의 개수
    cin >> n >> m;

    // 사다리와 뱀 위치 입력
    vector<int> move(101);
    for (int i = 1; i <= 100; i++) {
        move[i] = i; // 기본적으로 자기 자신으로 이동하도록 설정
    }

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        move[x] = y; // 사다리 위치 설정
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        move[x] = y; // 뱀 위치 설정
    }

    // BFS로 최단 경로 탐색
    queue<int> q;
    q.push(1); // 시작점 1
    board[1] = 0; // 시작점에서 이동 횟수 0

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) { // 주사위는 1부터 6까지 던질 수 있음
            int next = cur + i; // 주사위를 던져서 이동한 위치

            if (next > 100) continue; // 100칸을 넘어서면 안됨

            next = move[next]; // 사다리나 뱀이 있는 경우 이동

            if (board[next] > board[cur] + 1) { // 현재까지의 최소 이동 횟수보다 적으면 갱신
                board[next] = board[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << board[100]; // 100번째 칸까지의 최소 이동 횟수 출력

    return 0;
}
