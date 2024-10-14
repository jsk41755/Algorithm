#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char> &a) {
    while (!a.empty()) {
        cout << a.top();
        a.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    bool start = false;
    stack<char> a;

    getline(cin, t);

    for (char ch : t) {
        if (ch == '<') {
            start = true;
            print(a);
            cout << '<';
        }
        else if (ch == '>') {
            start = false;
            cout << '>';
        }
        else if (start == true) {
            cout << ch;
        }
        else if (ch == ' ') {
            print(a);
            cout << ' ';
        }
        else {
            a.push(ch);
        }
    }
    print(a);

    return 0;
}