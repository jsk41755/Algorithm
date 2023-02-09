#include <iostream>
#include <queue>

using namespace std;
int main(){
	int n, num;
	queue<int> que;
	string a;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			cin >> num;
			que.push(num);
		}
		else if (a == "pop") {
			if (que.empty() == true)
				cout << "-1" << endl;
			else {
				cout << que.front() << endl;
				que.pop();
			}
		}
		else if (a == "size") {
			cout << que.size() << endl;
		}
		else if (a == "empty") {
			if (que.empty() == true)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (a == "front") {
			if (que.empty() == true)
				cout << "-1" << endl;
			else
			cout << que.front() << endl;
		}
		else if (a == "back") {
			if (que.empty() == true)
				cout << "-1" << endl;
			else
				cout << que.back() << endl;
		}
	}

}