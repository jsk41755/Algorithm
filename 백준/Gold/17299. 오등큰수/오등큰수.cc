#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    stack<int> s;

    for (int i = 1; i <= n; i++) {
        while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]] && arr[s.top()] != arr[i]) {
            int top = s.top();
            s.pop();
            ans[top] = arr[i];
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            cout << -1 << " ";
        }
        else {
            cout << ans[i] << " ";
        }
    }

    return 0;
}
