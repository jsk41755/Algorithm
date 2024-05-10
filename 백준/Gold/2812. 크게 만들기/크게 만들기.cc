#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<char> result; // 결과를 저장할 벡터

    for (char digit : s) {
        while (k > 0 && !result.empty() && result.back() < digit) {
            // 현재 숫자가 결과에 추가될 수 있을 때까지 결과에서 숫자를 제거
            result.pop_back();
            k--;
        }
        result.push_back(digit); // 현재 숫자를 결과에 추가
    }

    // 남은 제거할 숫자가 있다면 뒤에서부터 제거
    while (k > 0) {
        result.pop_back();
        k--;
    }

    // 결과 출력
    for (char digit : result) {
        cout << digit;
    }

    return 0;
}
