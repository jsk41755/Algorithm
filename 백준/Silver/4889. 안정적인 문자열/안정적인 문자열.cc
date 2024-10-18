#include <iostream>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int stage = 1;

    while (1) {
        int cnt = 0;
        string s;

        cin >> s;

        if (s[0] == '-') return 0;

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                st.push('{');
            }
            else {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                }
                else {
                    cnt++;
                    st.push('{');
                }
            }
        }


        cout << stage++ << ". " << st.size() / 2 + cnt << "\n";
    }

    return 0;
}
