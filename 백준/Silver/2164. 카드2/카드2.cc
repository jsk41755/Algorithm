#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	queue<int> myQueue;
	
	for (int i = 1; i < N+1; i++) {
		myQueue.push(i);
	}

	while (myQueue.size() > 1) {
		myQueue.pop();
		myQueue.push(myQueue.front());
		myQueue.pop();
	}

	cout << myQueue.front() << "\n";

}