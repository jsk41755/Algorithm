#include <iostream>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<char> st;
    stack<char> st2;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] > '0' && s[i] <= '9') {
            cnt++;
        }
        else if (s[i] == 'L') {
            st.push('L');
        }
        else if (s[i] == 'R') {
            if (!st.empty() && st.top() == 'L') {
                st.pop();
                cnt++;
            }
            else {
                break;
            }
        }
        else if (s[i] == 'S') {
            st2.push('S');
        }
        else if(s[i] == 'K') {
            if (!st2.empty() && st2.top() == 'S') {
                st2.pop();
                cnt++;
            }
            else {
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}
