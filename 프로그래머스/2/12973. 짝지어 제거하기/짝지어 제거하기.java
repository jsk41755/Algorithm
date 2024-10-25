import java.util.*;

class Solution
{
    public int solution(String s)
    {
        int answer = 0;
        ArrayDeque<Character> st = new ArrayDeque<>();
        
        for(int i=0; i<s.length(); i++){
            if(!st.isEmpty() && st.peek() == s.charAt(i)){
                st.pop();
                continue;
            }
            st.push(s.charAt(i));
        }
        if(st.isEmpty()) answer = 1;
        
        return answer;
    }
}