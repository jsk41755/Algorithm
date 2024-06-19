#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    vector<int> v;

    cin >> n;

    int l = 0, r = 0;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        r = max(r, num);
    }

    cin >> m;

    int result, sum;

    while (l <= r) {
        sum = 0;
        int mid = (l + r) / 2;

        for (int i = 0; i < n; i++) {
            sum += min(v[i], mid);
        }

        if (m >= sum) {
            result = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << result;

    return 0;
}
