#include <iostream>
#include <queue>
#include <stack>
using namespace std;

long long a, b;
int cnt = 0;

void rec(long long num) {
    if (num <= b) {
        if (a <= num) {
            cnt++;
        }
        num *= 10;
        rec(num + 4);
        rec(num + 7);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    rec(4);
    rec(7);

    cout << cnt;


    return 0;
}
