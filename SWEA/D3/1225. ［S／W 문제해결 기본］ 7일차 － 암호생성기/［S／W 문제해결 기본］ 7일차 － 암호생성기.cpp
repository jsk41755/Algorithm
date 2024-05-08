#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T = 0;
    //cin >> T;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        queue<int> q;
        int num;

        for (int i = 0; i < 8; i++) {
            cin >> num;
            q.push(num);
        }

        int cnt = 1;

        while (q.back() > 0) {
            if (cnt == 6) {
                cnt = 1;
            }

            int t = q.front();
            q.pop();
            t -= cnt;

            if (t <= 0) {
                t = 0;
            }
            cnt++;
            q.push(t);
        }

        cout << "#" << test_case << " ";

        for (int i = 0; i < 8; i++) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }

    return 0;
}