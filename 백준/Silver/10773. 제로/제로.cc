#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            s.pop();
        }
        else {
            s.push(num);
        }
    }

    int sol = 0;

    while (!s.empty()) {
        sol += s.top();
        s.pop();
    }
    
    cout << sol;

    return 0;
}
