#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long a, b;
int result = 1987654321;

void rec(long long num, int cnt) {
    if (num == b) {
        result = min(result, cnt);
        return;
    }
    else if (num < b) {
        rec(num * 2, cnt + 1);
        rec(num * 10 + 1, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> a >> b;

    rec(a, 1);

    if (result == 1987654321) cout << -1;
    else cout << result;


    return 0;
}
