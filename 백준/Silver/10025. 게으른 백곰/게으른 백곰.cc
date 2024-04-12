#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<int> a(1000001, 0);

    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;

        a[x] = g;
    }

    int mx = 0;
    k = 2 * k + 1;

    int sum = 0;
    
    for (int i = 0; i < 1000001; i++) {
        if (i >= k) {
            sum -= a[i - k];
        }
        sum += a[i];
        mx = max(mx, sum);
    }

    cout << mx;

    return 0;
}