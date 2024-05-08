#include<iostream>
#include<vector>
#include<string>
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
        string s;
        cin >> s;

        string cmd = "";

        for (int i = 0; i < s.size(); i++) {
            cmd += '0';
        }

        int sol = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != cmd[i]) {
                sol++;
                if (cmd[i] == '0') {
                    for (int j = i; j < s.size(); j++) {
                        cmd[j] = '1';
                    }
                }
                else {
                    for (int j = i; j < s.size(); j++) {
                        cmd[j] = '0';
                    }
                }
                
            }
        }


        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}