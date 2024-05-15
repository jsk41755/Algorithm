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
    //cin >> T;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;

        char arr[100][100];
        int sol = 0;

        for (int i = 0; i < 100; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 100; j++) {
                arr[i][j] = s[j];
            }
        }

        //if (n % 2 == 1) n++;

        //가로
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int cnt = 0;

                for (int k = 99; k >= j; k--) {
                    if (arr[i][j + cnt] == arr[i][k]) {
                        cnt += 1;
                    }
                    else {
                        cnt = 0;
                    }

                }

                sol = max(sol, cnt);
            }

        }

        //세로
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int cnt = 0;

                for (int k = 99; k >= j; k--) {
                    if (arr[j + cnt][i] == arr[k][i]) {
                        cnt += 1;
                    }
                    else {
                        cnt = 0;
                    }

                }

                sol = max(sol, cnt);
            }

        }

        cout << "#" << n << " " << sol << "\n";
    }

    return 0;
}