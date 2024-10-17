#include <iostream>
#include <string>
using namespace std;

long long meter_conversion(long long num) {
    string s = to_string(num);
    long long result = 0, factor = 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        if (digit > 4) digit--;
        result += digit * factor;
        factor *= 9;
    }

    return result;
}

int main() {
    long long num;
    cin >> num;
    cout << meter_conversion(num) << '\n';
    return 0;
}