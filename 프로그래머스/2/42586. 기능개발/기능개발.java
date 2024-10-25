import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> list = new ArrayList<>();
        
        int cnt = 0;
        while(cnt < progresses.length){
            ArrayDeque<Integer> que = new ArrayDeque<>();
            
            int k = 0;
            for(int i=cnt; i<progresses.length; i++){
                progresses[i] += speeds[i];
                que.addLast(progresses[i]);
            }
            
            while(!que.isEmpty() && que.peekFirst() >= 100){
                que.removeFirst();
                cnt++;
                k++;
            }
            
            if(k>0) list.add(k);
        
        }
        
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }
        
        
        return answer;
    }
}