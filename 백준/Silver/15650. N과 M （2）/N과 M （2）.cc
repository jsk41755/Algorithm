#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int n, m;

vector<int> v;

void func(int i, int cnt) {
    if (cnt == m) {
        for (int j = 0; j < cnt; j++) {
            cout << v[j] << " ";
        }
        cout << "\n";
        return;
    }

    for (int j = i + 1; j <= n; j++) {
        v[cnt] = j;
        func(j, cnt + 1);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(m);

    for (int i = 1; i <= n; i++) {
        v[0] = i;
        func(i, 1);
    }

    return 0;
}
