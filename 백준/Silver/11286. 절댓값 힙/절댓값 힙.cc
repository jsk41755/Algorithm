#include<iostream>
#include<queue>
using namespace std;

struct cmp { // 정렬 기준 바꾸는 함수
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b; // 절대값이 같은 경우 가장 작은 원소로
        return abs(a) > abs(b); // 절대값이 작은 원소로
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    priority_queue<int, vector<int>, cmp> q;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (q.empty()) {
                // 큐가 비어있을 때 0을 출력
                v.push_back(0);
            }
            else {
                v.push_back(q.top()); // 가장 작은 원소 출력
                q.pop(); // 제거
            }
        }
        else {
            q.push(x); // 원소 추가
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n'; // 정답 출력
    }

    return 0;
}
