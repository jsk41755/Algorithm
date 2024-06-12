#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    long long answer = 0;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        int num;

        cin >> num;

        if (s.empty()) {
            s.push(num);
            continue;
        }

        while (!s.empty() && s.top() <= num) {
            s.pop();
        }

        answer += s.size();

        s.push(num);
    }

    cout << answer;

    return 0;
}
