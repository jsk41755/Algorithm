#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int cnt = 0;
    int sol = 0;

    while (n > 0) {
        cnt++;
        if (cnt > n) {
            cnt = 0;
            continue;
        }
        else {
            n -= cnt;
        }

        sol++;
    }

    cout << sol;

    return 0;
}
