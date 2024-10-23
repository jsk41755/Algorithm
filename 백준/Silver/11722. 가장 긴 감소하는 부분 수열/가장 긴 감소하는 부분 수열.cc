#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1002];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    dp[0] = 1;
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        int num = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[i]) {
                num = max(num, dp[j]);
            }
        }
        dp[i] = num + 1;
        cnt = max(cnt, dp[i]);
    }

    cout << cnt;

    return 0;
}
