#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
int building[500001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    stack<int> s;

    for (int i = n; i >= 1; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            int top = s.top();
            s.pop();
            building[top] = i;
        }

        s.push(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << building[i] << " ";
    }

    return 0;
}
