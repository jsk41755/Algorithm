#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> result;
int n, m;

void rec(int cnt, int start) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < v.size(); i++) {
        result.push_back(v[i]);
        rec(cnt + 1, i); // 중복을 허용하기 때문에 i를 넘김 (start가 아닌 i)
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 중복을 제거하고 정렬
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    rec(0, 0);

    return 0;
}
