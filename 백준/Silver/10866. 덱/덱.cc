#include<iostream>
#include<deque>

using namespace std;

int main() {
	int N, num;
	string K;
	deque<int> deq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> K;

		if (K == "push_front") {
			cin >> num;
			deq.push_front(num);
		}
		else if (K == "push_back") {
			cin >> num;
			deq.push_back(num);
		}
		else if (K == "pop_front") {
			if (deq.empty() == true)
				cout << "-1" << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (K == "pop_back") {
			if (deq.empty() == true)
				cout << "-1" << endl;
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (K == "size") {
			cout << deq.size() << endl;
		}
		else if (K == "empty") {
			if (deq.empty() == true)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (K == "front") {
			if (deq.empty() == true) {
				cout << "-1" << endl;
			}
			else
			cout << deq.front() << endl;
		}
		else if (K == "back") {
			if (deq.empty() == true) {
				cout << "-1" << endl;
			}
			else
			cout << deq.back() << endl;
		}
	}
}