#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
int many[100001];
int building[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    stack<int> s;

    for (int i = 1; i <= n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            many[i] += s.size();
            building[i] = s.top();
        }

        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n; i >= 1; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            many[i] += s.size();
            if (building[i] == 0 || abs(i - building[i]) > abs(i - s.top())) {
                building[i] = s.top();
            }
        }

        s.push(i);
    }

    

    for (int i = 1; i <= n; i++) {
        if (many[i] == 0) {
            cout << 0 << "\n"; 
        }
        else {
            cout << many[i] << " " << building[i] << "\n";
        }
    }

    return 0;
}
