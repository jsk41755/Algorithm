#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt =1;
    cin >> n;
    int a = 1;

    while (true) {
        if (a < n) {
            a += cnt * 6;
            cnt++;
        }
        else {
            break;
        }
    }

    cout << cnt;
}