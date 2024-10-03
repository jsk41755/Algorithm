#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool isChecked[51];
bool isChecked1[51];
bool isChecked2[51];

int n, cnt = 0;

void func(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!isChecked[i] && !isChecked1[i+cur] && !isChecked2[cur-i+n-1]) {
            isChecked[i] = true;
            isChecked1[i + cur] = true;
            isChecked2[cur - i + n - 1] = true;
            func(cur + 1);
            isChecked[i] = false;
            isChecked1[i+cur] = false;
            isChecked2[cur-i+n-1] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    func(0);

    cout << cnt;

    return 0;
}