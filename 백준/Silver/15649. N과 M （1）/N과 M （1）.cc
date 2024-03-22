#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

int b[9];
bool visit[9];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            b[k] = i;
            visit[i] = true;
            func(k + 1);
            visit[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
    
}