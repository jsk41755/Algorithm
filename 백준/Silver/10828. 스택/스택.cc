#include<iostream>
#include<stack>

using namespace std;

int main() {
	int N, a;
	string order;
	stack<int> st;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == "push") {
			cin >> a;
			st.push(a);
		}
		else if (order == "pop") {
			if(st.empty())
			cout << "-1" << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (order == "size") {
			cout << st.size() << endl;
		}
		else if (order == "empty") {
			if (st.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (order == "top") {
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.top() << endl;
		}
	}
}