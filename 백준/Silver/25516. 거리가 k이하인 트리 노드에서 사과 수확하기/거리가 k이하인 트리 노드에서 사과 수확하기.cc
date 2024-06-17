#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v(100001);
int n, k;
int sol = 0;
int arr[100001];
bool isVisit[100001];

void dfs(int t, int count) {
    if (count > k) {
        return;
    }
    sol += arr[t];
    isVisit[t] = true;

    for (int i = 0; i < v[t].size(); i++) {
        if (!isVisit[v[t][i]]) {
            dfs(v[t][i], count + 1);
        }
    }

    isVisit[t] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;
        v[p].push_back(c);
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    cout << sol;

    return 0;
}
