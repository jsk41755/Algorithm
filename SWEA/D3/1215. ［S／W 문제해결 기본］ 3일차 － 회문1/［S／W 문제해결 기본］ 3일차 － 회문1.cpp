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

        char arr[8][8];
        int sol = 0;

        for (int i = 0; i < 8; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < 8; j++) {
                arr[i][j] = s[j];
            }
        }

        //if (n % 2 == 1) n++;

        //가로
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - n; j++) {
                int cnt = 1;
                int correct = 0;

                for (int k = j; k < j + (n / 2); k++) {
                    if (arr[i][k] == arr[i][j + n - cnt]) {
                        correct++;
                    }
                    else {
                        break;
                    }
                    cnt++;
                }

                if (correct == n/2) {
                    sol++;
                }
            }
        }

        //세로
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - n; j++) {
                int cnt = 1;
                int correct = 0;

                for (int k = j; k < j + (n / 2); k++) {
                    if (arr[k][i] == arr[j + n - cnt][i]) {
                        correct++;
                    }
                    else {
                        break;
                    }
                    cnt++;
                }

                if (correct == n / 2) {
                    sol++;
                }
            }
        }


        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}