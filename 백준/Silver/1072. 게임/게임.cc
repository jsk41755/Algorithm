#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long x, y;
	cin >> x >> y;

	int z = (y * 100) / x ;

	if (z >= 99) {
		cout << -1;
		return 0;
	}

	int l = 1, r = 1000000000;
	int result = -1;

	while (l <= r) {
		int half = (l + r) / 2;  // 중간값을 정수로 계산
		int new_z = ((y + half) * 100) / (x + half);  // 새로운 승률 계산

		if (new_z > z) {  // 승률이 더 높아졌다면
			result = half;  // 결과 갱신
			r = half - 1;   // 범위를 줄여서 더 적은 값도 가능한지 확인
		}
		else {
			l = half + 1;   // 승률이 충분히 안 올랐다면 더 많은 게임을 탐색
		}
	}

	cout << result;

	return 0;
}