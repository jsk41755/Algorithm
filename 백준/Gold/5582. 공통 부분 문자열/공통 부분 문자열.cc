#include<iostream>
#include<vector>
#include<string>

using namespace std;

string a, b;
int sol[4001][4001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    int answer = 0;
    for (int i = 1; i <= b.size(); i++) {
        for (int j = 1; j <= a.size(); j++) {
            if (b[i-1] == a[j-1]) {
                sol[i][j] += sol[i - 1][j - 1] + 1;
            }
            answer = max(answer, sol[i][j]);
        }
    }

    cout << answer;

    return 0;
}