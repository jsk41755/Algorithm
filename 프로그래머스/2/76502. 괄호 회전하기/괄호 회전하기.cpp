#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> deq;
    string change = s;
    
    if(s.size() % 2 == 1) return 0;
    
    for(int i=0; i<s.size(); i++){
        
        string ch = "";
        
        for(int j=i; j<s.size(); j++){
            ch += change[j];
        }
        
        for(int j=0; j<i; j++){
            ch += change[j];
        }
        
        stack<char> st;
        stack<char> en;
        
        for(int j=0; j<s.size(); j++){
            st.push(ch[j]);
        }
        
        for(int j=0; j<s.size()/2; j++){
            char c = st.top();
            
            if(st.top() == '}' || st.top() == ')' || st.top() == ']'){
                en.push(c);
                st.pop();
            } else {
                break;
            }
            
            while(!en.empty()){
                if(en.top() == '}' && st.top() == '{'){
                    en.pop();
                    st.pop();
                } else if(en.top() == ')' && st.top() == '('){
                    en.pop();
                    st.pop();
                } else if(en.top() == ']' && st.top() == '['){
                    en.pop();
                    st.pop();
                } else break;
            }
        }
        
        if(st.empty() && en.empty()) answer++;
    }
    
    return answer;
}