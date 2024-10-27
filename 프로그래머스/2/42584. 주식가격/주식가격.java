import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        ArrayDeque<Integer> st = new ArrayDeque<>();
        ArrayList<Integer> list = new ArrayList<>();
        
        int cnt = 1;
        for(int i=0; i<prices.length; i++){
            while(!st.isEmpty() && prices[i] < prices[st.peekFirst()]){
                int top = st.peekFirst();
                st.pop();
                answer[top] = i-top;
            }
            st.push(i);
        }
        
        while(!st.isEmpty()){
                int top = st.peekFirst();
                st.pop();
                answer[top] = prices.length - top -1;
        }
        
        return answer;
    }
}