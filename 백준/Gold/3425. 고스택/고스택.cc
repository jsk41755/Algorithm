#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define max_value 1000000000
#define min_value -1000000000
using namespace std;

stack<long long> st;

void num(int x) {
    st.push(x);
}

int pop() {
    if (st.empty()) {
        return -1;
    } else {
        st.pop();
        return 1;
    }
}

int inv() {
    if (st.empty()) {
        return -1;
    } else {
        long long temp = st.top() * -1;
        st.pop();
        st.push(temp);
        return 1;
    }
}

int dup() {
    if (st.empty()) {
        return -1;
    } else {
        st.push(st.top());
        return 1;
    }
}

int swp() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        st.push(first);
        st.push(second);
        return 1;
    }
}

int add() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = first + second;
        if (temp < min_value ||temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int sub() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = second - first;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int mul() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = first * second;
        if (temp < min_value ||temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int div() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        if (first == 0) {
            return -1;
        }
        long long temp = second / first;
        if (temp < min_value ||temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int mod() {
    if (st.size() < 2) {
        return -1;
    } else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        if (first == 0) {
            return -1;
        }
        long long temp = second % first;
        if (temp < min_value ||temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int main() {
    while (true) {
        vector<string> vec;
        string str;

        while (true) {
            cin >> str;
            if (str == "END") {
                break;
            } else if (str == "QUIT") {
                return 0;
            }
            vec.push_back(str);
        }
        int N;
        cin >> N;
        while(N--) {
            long long initial;
            cin >> initial;
            int errFlag = 0;
            st.push(initial);
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == "NUM") {\
                num(stoi(vec[i+1]));
                    i += 1;
                } else if (vec[i] == "POP") {
                    errFlag = pop();
                } else if (vec[i] == "INV") {
                    errFlag = inv();
                } else if (vec[i] == "DUP") {
                    errFlag = dup();
                } else if (vec[i] == "SWP") {
                    errFlag = swp();
                } else if (vec[i] == "ADD") {
                    errFlag = add();
                } else if (vec[i] == "SUB") {
                    errFlag = sub();
                } else if (vec[i] == "MUL") {
                    errFlag = mul();
                } else if (vec[i] == "DIV") {
                    errFlag = div();
                } else if (vec[i] == "MOD") {
                    errFlag = mod();
                }

                if (errFlag == -1) {
                    cout << "ERROR" << '\n';
                    while (!st.empty()) {
                        st.pop();
                    }
                    break;
                }
            }

            if (errFlag == -1) {
                continue;
            }

            if (st.size() != 1) {
                cout << "ERROR" << '\n';
                while (!st.empty()) {
                    st.pop();
                }
            } else {
                cout << st.top() << '\n';
                st.pop();
            }

        }
        cout << '\n';
    }

    return 0;
}