#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int lab[8][8];            // 연구소 원본 지도
int temp[8][8];           // 벽을 세우고 난 후 바이러스 확산을 시뮬레이션할 지도
int dx[4] = { -1, 1, 0, 0 };  // 상, 하, 좌, 우 방향
int dy[4] = { 0, 0, -1, 1 };  // 상, 하, 좌, 우 방향
int max_safe_area = 0;        // 최대 안전 영역 크기

// BFS를 사용해 바이러스를 확산시키는 함수
void spreadVirus() {
    int spreadLab[8][8];
    queue<pair<int, int>> q;

    // temp 배열을 복사해 spreadLab 배열을 만듦 (바이러스 확산 시뮬레이션용)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            spreadLab[i][j] = temp[i][j];
            if (spreadLab[i][j] == 2) {  // 바이러스 위치를 큐에 삽입
                q.push({i, j});
            }
        }
    }

    // BFS로 바이러스를 확산
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 연구소 범위를 벗어나지 않고 빈 칸(0)인 경우 바이러스 확산
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && spreadLab[nx][ny] == 0) {
                spreadLab[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }

    // 안전 영역의 크기 계산
    int safe_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spreadLab[i][j] == 0) {
                safe_area++;
            }
        }
    }

    // 최대 안전 영역 크기 갱신
    max_safe_area = max(max_safe_area, safe_area);
}

// 벽을 3개 세우는 백트래킹 함수
void buildWall(int count) {
    // 벽이 3개 세워지면 바이러스를 확산시키고 안전 영역을 계산
    if (count == 3) {
        spreadVirus();
        return;
    }

    // 벽을 세울 위치 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {  // 빈 공간(0)인 곳에 벽을 세움
                temp[i][j] = 1;
                buildWall(count + 1);
                temp[i][j] = 0;  // 백트래킹: 벽을 다시 없앰
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    // 연구소 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    // 백트래킹으로 벽을 세우고 안전 영역을 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {  // 빈 공간(0)인 경우에만 벽을 세움
                // temp 배열을 현재 상태로 초기화
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < m; b++) {
                        temp[a][b] = lab[a][b];
                    }
                }

                temp[i][j] = 1;  // 첫 번째 벽 세움
                buildWall(1);    // 벽을 3개 세우기 위한 백트래킹 시작
                temp[i][j] = 0;  // 백트래킹 후 벽을 다시 없앰
            }
        }
    }

    // 최대 안전 영역 크기 출력
    cout << max_safe_area << "\n";

    return 0;
}
