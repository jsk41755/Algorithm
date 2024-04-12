#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a;
vector<int> ans;

void rec(int t, int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1; // 이전에 선택한 숫자를 저장할 변수
    for (int i = t; i < n; i++) {

        if (prev == a[i]) { // 이전에 선택한 숫자와 같다면 건너뜀
            continue;
        }

        ans[cnt] = a[i]; // 현재 숫자를 선택함
        prev = a[i]; // 이전에 선택한 숫자 갱신

        rec(i + 1, cnt + 1); // 다음 숫자를 선택하기 위해 재귀 호출
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    a.resize(n);
    ans.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    rec(0, 0);


    return 0;
}
