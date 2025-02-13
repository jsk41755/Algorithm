import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        int[] list = new int[N+2];
        
        for(int i=0; i<stages.length; i++){
            list[stages[i]]++;    
        }
        
        HashMap<Integer, Double> fail = new HashMap<>();
        double tot = stages.length;
        
        for(int i=1; i<=N; i++){
            if(list[i] == 0){
                fail.put(i, 0.);
            } else{
                fail.put(i, list[i]/tot);
                tot -= list[i];
            }
        }
        
        for(int i=1; i<=N; i++){
            double ma = -1;
            int ke = 0;
            for(int key: fail.keySet()){
                if(ma < fail.get(key)){
                    ke = key;
                    ma = fail.get(key);
                }
            }
            fail.remove(ke);
            answer[i-1] = ke;
        }
        
        return answer;
    }
}