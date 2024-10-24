#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
long long dp[100002];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sol = arr[0];

    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + (long long)arr[i], (long long)arr[i]);
        sol = max(sol, dp[i]);
    }


    cout << sol;


    return 0;
}
