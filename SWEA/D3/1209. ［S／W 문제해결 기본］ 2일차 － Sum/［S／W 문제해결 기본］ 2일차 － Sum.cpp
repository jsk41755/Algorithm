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
        int hor[101] = { 0, };
        int ver[101] = { 0, };
        int lCross = 0;
        int rCross = 0;

        int num = 0;
        
        int n = 0;
		cin >> n;

        for (int i = 1; i < 101; i++) {
            for (int j = 1; j < 101; j++) {
                cin >> num;

                if (i == j) {
                    lCross += num;
                }

                if (i + j == 101) {
                    rCross += num;
                }
                
                ver[i] += num;
                hor[j] += num;
            }
        }
        int sol = 0;
        for (int i = 1; i < 101; i++) {
            sol = max(sol, max(ver[i], hor[i]));
        }

        sol = max(sol, max(lCross, rCross));

        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}