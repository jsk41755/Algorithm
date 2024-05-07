#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int dump;
        cin >> dump;
        vector<int> v(100);

        for (int i = 0; i < 100; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < dump; i++) {
            v[99]--;
            v[0]++;
            sort(v.begin(), v.end());
        }

        int sol = v[99] - v[0];
        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}