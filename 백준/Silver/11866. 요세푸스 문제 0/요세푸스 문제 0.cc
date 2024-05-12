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

    queue<int> q;
    queue<int> p;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        int cnt = 0;

        while (cnt < k) {
            int temp = q.front();
            q.pop();

            if (cnt == k - 1) {
                p.push(temp);
                break;
            }

            q.push(temp);
            cnt++;
        }
    }

    cout << "<";

    for (int i = 0; i < n-1; i++) {
        cout << p.front() << ", ";
        p.pop();
    }

    cout << p.front();
    cout << ">";

    return 0;
}
