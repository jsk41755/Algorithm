#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, d;
int arr[16][16]; // 게임판
int total = 0;   // 최대 적 처치 수

// 적 위치를 추적하는 배열 (임시 복사본)
int temp[16][16];

// 궁수가 공격할 적을 찾는 함수
pair<int, int> find_target(int x) {
    int min_dist = d + 1;
    pair<int, int> target = { -1, -1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 1) {  // 적이 있는 곳
                int dist = abs(n - i) + abs(x - j);
                if (dist <= d) {
                    if (dist < min_dist || (dist == min_dist && j < target.second)) {
                        target = { i, j };
                        min_dist = dist;
                    }
                }
            }
        }
    }

    return target;  // 공격할 적의 위치
}

// 궁수 배치와 공격을 처리하는 재귀 함수
void simulate(vector<int> archers) {
    copy(&arr[0][0], &arr[0][0] + 16 * 16, &temp[0][0]);  // arr을 temp로 복사
    int hunt = 0; // 현재 경우에서 제거된 적 수

    // n번 턴만큼 진행 (적이 이동할 수 있는 최대 턴)
    for (int t = 0; t < n; t++) {
        vector<pair<int, int>> targets;

        // 각 궁수마다 공격 대상 선정
        for (int i = 0; i < 3; i++) {
            pair<int, int> target = find_target(archers[i]);
            if (target.first != -1) targets.push_back(target);
        }

        // 중복되지 않게 적을 제거
        for (auto target : targets) {
            if (temp[target.first][target.second] == 1) {
                temp[target.first][target.second] = 0;
                hunt++;
            }
        }

        // 적이 한 칸씩 아래로 이동
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = temp[i - 1][j];
            }
        }
        fill(temp[0], temp[0] + m, 0);  // 맨 윗줄을 0으로 초기화
    }

    total = max(total, hunt);  // 최대값 갱신
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 궁수의 위치 조합을 구함 (궁수는 3명)
    vector<int> archer_positions;
    for (int i = 0; i < m - 3; i++) {
        archer_positions.push_back(0);
    }
    for (int i = 0; i < 3; i++) {
        archer_positions.push_back(1);
    }

    do {
        vector<int> archers;
        for (int i = 0; i < m; i++) {
            if (archer_positions[i] == 1) archers.push_back(i);
        }
        simulate(archers);
    } while (next_permutation(archer_positions.begin(), archer_positions.end()));

    cout << total << "\n";

    return 0;
}
