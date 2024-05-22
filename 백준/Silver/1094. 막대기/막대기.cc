#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stick = 64;
int n;
int sol = 0;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if (n == 64) {
        cout << 1;
        return 0;
    }

    while (n != sol) {

        stick = stick >> 1;
        if (sol + stick <= n) {
            sol += stick;
            cnt++;
        }

    }

    cout << cnt;


    return 0;
}
