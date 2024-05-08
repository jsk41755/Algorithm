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

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int num;
        cin >> num;

        string search;

        cin >> search;
        
        string s;

        cin >> s;

        int slength = s.size() - search.size();
        int sol = 0;

        for (int i = 0; i <= slength; i++) {
            int cnt = 0;
            for (int j = i; j < i + search.size(); j++) {
                if (s[j] == search[cnt]) {
                    cnt++;
                }
            }
            if (cnt == search.size()) {
                sol++;
            }
        }


        cout << "#" << test_case << " " << sol << "\n";
    }

    return 0;
}