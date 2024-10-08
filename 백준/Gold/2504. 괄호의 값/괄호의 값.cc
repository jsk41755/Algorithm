#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    int sum = 0;
    int val = 1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
            val *= 2;  // '('가 나오면 2를 곱함
        }
        else if (s[i] == '[') {
            st.push(s[i]);
            val *= 3;  // '['가 나오면 3을 곱함
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') { // 괄호가 맞지 않으면 잘못된 괄호
                sum = 0;
                break;
            }
            if (s[i - 1] == '(') sum += val;  // 직전에 '('가 있으면 값을 더함
            st.pop();
            val /= 2;  // 닫힌 괄호이므로 2를 나눔
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') { // 괄호가 맞지 않으면 잘못된 괄호
                sum = 0;
                break;
            }
            if (s[i - 1] == '[') sum += val;  // 직전에 '['가 있으면 값을 더함
            st.pop();
            val /= 3;  // 닫힌 괄호이므로 3을 나눔
        }

    }

    if (!st.empty()) sum = 0;  // 남은 괄호가 있으면 잘못된 괄호

    cout << sum;

    return 0;
}
