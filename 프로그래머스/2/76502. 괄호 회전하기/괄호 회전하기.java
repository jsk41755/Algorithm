import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int n = s.length();
        s += s;
        
        for(int i=0; i<n; i++){
            ArrayDeque<Character> st = new ArrayDeque<>();
            boolean isValid = true;
            
            for(int j=i; j<i+n; j++){
                
                if(s.charAt(j) == '{' || s.charAt(j) == '[' || s.charAt(j) == '('){
                    st.push(s.charAt(j));
                } else{
                    if(!st.isEmpty()){
                        if(st.peek() == '{' && s.charAt(j) == '}'){
                            st.pop();
                        } else if(st.peek() == '[' && s.charAt(j) == ']') {
                            st.pop();
                        } else if(st.peek() == '(' && s.charAt(j) == ')') {
                            st.pop();
                        } else {
                            isValid = false;
                            break;
                        }
                    } else {
                        isValid = false;
                        break;
                    }
                }
            }
            if (isValid && st.isEmpty()) {
                    answer++;
                }
            
        }
        
        return answer;
    }
}