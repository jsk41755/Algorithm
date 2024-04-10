#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> seq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    cin >> n;

    a.resize(n);
    seq.resize(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int tmp = 0;

        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                tmp = max(tmp, seq[j]);
            }
        }

        seq[i] = tmp +1;
        cnt = max(seq[i], cnt);
    }

    cout << cnt;

    return 0;
}
