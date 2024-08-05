#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<int> v;

long long l = 0, r = 0;

long long binary_search(long long st, long long en) {

    while (st < en) {
        long long mid = (st + en) / 2;
        int cnt = 0;

        for (int i = 0; i < k; i++) {
            cnt += v[i] / mid;
        }

        if (cnt < n) {
            en = mid;
        }
        else {
            st = mid + 1;
        }
    }

    return st;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        long long num = 0;
        cin >> num;
        v.push_back(num);

        r = max(r, num);
    }

    long long sol = binary_search(0, r+1);

    cout << sol - 1;

    return 0;
}
