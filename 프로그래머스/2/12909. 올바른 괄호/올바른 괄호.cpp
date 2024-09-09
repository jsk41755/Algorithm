#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        if(st.empty() || s[i] == '('){
            st.push('(');
        } else if(!st.empty() && st.top() == '('){
            st.pop();
        }
    }
    
    if(!st.empty()) answer = false;

    return answer;
}