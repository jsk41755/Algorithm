#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<float> v;
		float num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			int k;
			cin >> k;
			v.push_back(k);
		}

		float sum = 0;
		for (int j = 0; j < v.size(); j++) {
			sum += v[j];
		}

		sum /= v.size();

		int cnt = 0;

		for (int j = 0; j < v.size(); j++) {
			if (sum < v[j]) {
				cnt++;
			}
		}

		float sol = cnt / num * 100;

		printf("%.3f", sol);
		cout << "%" << "\n";
	}
	return 0;
}