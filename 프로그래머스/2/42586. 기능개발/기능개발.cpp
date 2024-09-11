#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size(); // 기능의 개수
    int current = 0;           // 현재 배포할 기능의 인덱스

    while (current < n) {
        // 각 기능의 진행 상황 업데이트
        for (int i = 0; i < n; i++) {
            progresses[i] += speeds[i];
        }

        // 이번에 배포할 수 있는 기능들의 수를 셉니다.
        int count = 0;
        while (current < n && progresses[current] >= 100) {
            count++;
            current++; // 배포된 기능의 인덱스 이동
        }

        // 배포할 기능이 있다면 그 수를 저장
        if (count > 0) {
            answer.push_back(count);
        }
    }

    return answer;
}
