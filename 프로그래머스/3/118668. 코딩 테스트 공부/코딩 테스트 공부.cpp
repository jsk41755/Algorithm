#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 코딩 실력과 체력 모두 목표에 도달하는 최소 시간을 구하는 함수
int solution(int alp, int cop, vector<vector<int>> problems) {
    // 목표 코딩 실력과 체력
    int alp_req = 0, cop_req = 0;

    // 각 문제를 확인하여 목표 코딩 실력과 체력 설정
    for (auto p : problems) {
        alp_req = max(alp_req, p[0]);
        cop_req = max(cop_req, p[1]);
    }

    // 현재 실력이 목표보다 높은 경우 필요 없는 계산을 방지
    alp = min(alp, alp_req);
    cop = min(cop, cop_req);

    // dp 테이블, dp[i][j]는 코딩 실력 i, 체력 j에서 목표까지 걸리는 최소 시간
    vector<vector<int>> dp(alp_req + 1, vector<int>(cop_req + 1, 1e9));

    // 초기 상태에서의 시간은 0
    dp[alp][cop] = 0;

    // DP 진행
    for (int i = alp; i <= alp_req; i++) {
        for (int j = cop; j <= cop_req; j++) {
            // 코딩 공부를 통해 alp를 1 증가시키는 경우 (시간은 1 증가)
            if (i + 1 <= alp_req) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

            // 체력 훈련을 통해 cop를 1 증가시키는 경우 (시간은 1 증가)
            if (j + 1 <= cop_req) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            // 각 문제를 푸는 경우
            for (auto p : problems) {
                int alp_need = p[0], cop_need = p[1], alp_reward = p[2], cop_reward = p[3], time_cost = p[4];

                // 현재 상태가 해당 문제를 풀 수 있는지 확인
                if (i >= alp_need && j >= cop_need) {
                    // 문제를 풀고 코딩 실력과 체력이 증가하는 경우
                    int new_alp = min(i + alp_reward, alp_req);
                    int new_cop = min(j + cop_reward, cop_req);
                    dp[new_alp][new_cop] = min(dp[new_alp][new_cop], dp[i][j] + time_cost);
                }
            }
        }
    }

    // 목표 코딩 실력과 체력에서의 최소 시간을 반환
    return dp[alp_req][cop_req];
}