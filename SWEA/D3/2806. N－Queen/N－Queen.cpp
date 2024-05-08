#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isused[40];
bool isused1[40];
bool isused2[40];

int num;
int sol = 0;

void func(int cnt) {
    if (cnt == num) {
        sol++;
        return;
    }

    for (int i = 0; i < num; i++) {
        if (!isused[i] && !isused1[i + cnt] && !isused2[i - cnt + num - 1]) {
            isused[i] = true;
            isused1[i + cnt] = true;
            isused2[i - cnt + num - 1] = true;
            func(cnt + 1);
            isused[i] = false;
            isused1[i + cnt] = false;
            isused2[i - cnt + num - 1] = false;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T = 0;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        num = 0;
        cin >> num;
        sol = 0;

        func(0);

        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}