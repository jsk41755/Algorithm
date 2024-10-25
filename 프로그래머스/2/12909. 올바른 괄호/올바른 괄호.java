import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        ArrayDeque<Character> st = new ArrayDeque<>();
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '('){
                st.push(s.charAt(i));
            }
            else{
                if(st.isEmpty() || st.pop() == s.charAt(i))
                    return false;
            }
        }

        return st.isEmpty();
    }
}