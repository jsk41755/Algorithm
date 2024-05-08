#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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
        int arr[50][50];
        int num;

        cin >> num;

        string s;

        int sol = 0;

        for (int j = 0; j < num; j++) {
            cin >> s;

            for (int k = 0; k < s.size(); k++) {
                arr[j][k] = s[k] - '0';
            }
        }

        for (int i = 0; i < num; i++) {
            if (i <= (num / 2)) {
                for (int j = (num / 2) - i; j <= (num / 2) + i; j++) {
                    sol += arr[i][j];
                }
            }
            else {
                for (int j = i - (num / 2); j <= (num / 2) + (num-i) -1; j++) {
                    sol += arr[i][j];
                }
            }
        }

        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}