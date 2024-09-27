#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    vector<int> v;
    
    int s1 = 0;
    int e1 = queue1.size() - 1;
    int s2 = queue1.size();
    int e2 = queue1.size()*2 - 1;
    
    int size = queue1.size() * 2;
    long long sum1 = 0, sum2 = 0;
        
    for (int q1: queue1) {
        sum1 += q1;
        v.push_back(q1);
    }
    
    for (int q2: queue2) {
        sum2 += q2;
        v.push_back(q2);
    }

    // 위치가 원래대로 돌아오면 각 큐의 원소 합을 같게 만들 수 없음
    while (answer <= size * 2) {
        if (sum1 < sum2) {
            sum1 += v[(++e1) % size];
            sum2 -= v[(s2++) % size];
        } else if (sum1 > sum2) {
            sum1 -= v[(s1++) % size];
            sum2 += v[(++e2) % size];
        } else return answer; // 두 큐의 합이 같으면 answer 반환
        
        answer++;
    }
    
    return -1;
}