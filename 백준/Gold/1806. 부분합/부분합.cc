#include <iostream>

using namespace std;

int n, s;
int a[100001];
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    arr[0] = 0;

    for (int i = 1; i <= n; i++) {
        arr[i] = a[i - 1] + arr[i - 1];
    }

    int cnt = 100001;
    int fir = 0, sec = 0;

    while (true) {
        if (fir == n + 1 || sec == n + 1 || fir > sec) break;

        if (arr[sec] - arr[fir] >= s) {
            int mn = sec - fir;
            cnt = min(cnt, mn);
            fir++;
        }
        else {
            sec++;
        }
    }

    if (cnt == 100001) {
        cout << 0;
        return 0;
    }

    if (cnt == 0) {
        cout << 1;
        return 0;
    }

    cout << cnt;

    return 0;
}