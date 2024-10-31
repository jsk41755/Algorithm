import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        ArrayDeque<Integer> que = new ArrayDeque<>();
        
        for(int i=0; i<bridge_length; i++){
            que.addLast(0);
        }
        
        int idx = 0;
        int cur = 0;
        while(idx < truck_weights.length){
            
            cur -= que.peekFirst();
            que.removeFirst();
            
            if(cur + truck_weights[idx] <= weight){
                que.addLast(truck_weights[idx]);
                cur += truck_weights[idx];
                idx++;
            } else {
                que.addLast(0);
            }
            
            answer++;
        }
        
        answer += bridge_length;
        
        return answer;
    }
}