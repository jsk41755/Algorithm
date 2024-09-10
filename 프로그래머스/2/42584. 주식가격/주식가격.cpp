#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size(), 0);
    stack<int> st;
    
    st.push(0);
    
    for(int i=1; i<prices.size(); i++){
        while(!st.empty() && prices[i] < prices[st.top()]){
            int j = st.top();
            st.pop();
            answer[j] = i- j;
        }
        st.push(i);
    }
    
    while(!st.empty()){
        int j = st.top();
        cout << j << "\n";
        st.pop();
        answer[j] = prices.size() - 1 - j;
    }
    
    
    return answer;
}