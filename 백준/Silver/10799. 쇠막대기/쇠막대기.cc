#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string cmd;
	int cnt = 0;

	cin >> cmd;

	for (int i = 0; i < cmd.size(); i++) {

		if (cmd[i] == '(') {
			a.push(cmd[i]);
		}
		else {
			if (cmd[i - 1] == ')') {
				a.pop();
				cnt++;
			}
			else {
				a.pop();
				cnt += a.size();
			}
		}
	}

	cout << cnt;

}