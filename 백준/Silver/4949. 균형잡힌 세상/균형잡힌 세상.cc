#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string s;
		getline(cin, s);

		stack<char> st;

		if (s[0] == '.') {
			return 0;
		}

		bool flag = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
				continue;
			} else if (s[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			} else if (s[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					flag = false;
					break;
				}
			}
		}

		if (st.empty() && flag) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}

	return 0;
}