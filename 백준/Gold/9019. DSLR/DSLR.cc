#include <iostream>
#include <string>
#include <queue>

using namespace std;
int visited[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        queue<pair<int, string>> q;

        fill(visited, visited + 10000, 0);
        visited[a] = 1;
        q.push({ a,"" });

        while (!q.empty()) {
            int num = q.front().first;
            string s = q.front().second;

            q.pop();

            if (num == b) {
                cout << s << "\n";
                break;
            }

            int D = (num * 2) % 10000;
            if (!visited[D]) {
                q.push({ D, s + 'D' });
                visited[D] = 1;
            }

            int S = (num == 0) ? 9999 : num - 1;
            if (!visited[S]) {
                q.push({ S, s + 'S' });
                visited[S] = 1;
            }

            int L = (num % 1000) * 10 + (num / 1000);
            if (!visited[L]) {
                q.push({ L, s + 'L' });
                visited[L] = 1;
            }

            int R = (num % 10) * 1000 + (num / 10);
            if (!visited[R]) {
                q.push({ R, s + 'R' });
                visited[R] = 1;
            }
        }

        
    }


    return 0;
}
