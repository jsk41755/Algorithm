#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int mx = -1987654321;
int mi = 1987654321;

vector<int> a;
vector<int> v;

int n;

void dfs(int sum, int cnt) {
    if (n == cnt) {
        mx = max(mx, sum);
        mi = min(mi, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (a[i] > 0) {
            int original_sum = sum;
            if (i == 0) {
                sum += v[cnt];
            }
            else if (i == 1) {
                sum -= v[cnt];
            }
            else if (i == 2) {
                sum *= v[cnt];
            }
            else {
                sum /= v[cnt];
            }
            a[i]--;
            dfs(sum, cnt + 1);
            a[i]++;
            sum = original_sum;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }


    for (int i = 0; i < 4; i++) {
        int num2;
        cin >> num2;
        a.push_back(num2);
    }

    dfs(v[0], 1);

    cout << mx << " " << mi;

    return 0;
}
