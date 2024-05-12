#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    int cnt = 0;

    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n - 1; j++) {
            for (int k = j+1; k < n; k++) {
                if (v[i] + v[j] + v[k] <= m) {
                    cnt = max(cnt, (v[i] + v[j] + v[k]));
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
