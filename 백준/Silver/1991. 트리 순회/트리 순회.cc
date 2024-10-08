#include <iostream>
#include <vector>
#include <string>

using namespace std;
int num;
int arr[27][3];

void inorder(int n) {
	if (n == 0) return;

	inorder(arr[n][0]);
	char a = n + 'A' - 1;
	cout << a;
	inorder(arr[n][1]);
}

void preorder(int n) {
	if (n == 0) return;

	char a = n + 'A' - 1;
	cout << a;
	preorder(arr[n][0]);
	preorder(arr[n][1]);
}


void postorder(int n) {
	if (n == 0) return;

	postorder(arr[n][0]);
	postorder(arr[n][1]);
	char a = n + 'A' - 1;
	cout << a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')arr[a - 'A' + 1][0] = b - 'A' + 1;
		if (c != '.')arr[a - 'A' + 1][1] = c - 'A' + 1;
	}

	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);

	return 0;
}