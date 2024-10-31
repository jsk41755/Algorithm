import java.util.*;

class Solution {
    
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i=0; i<tangerine.length; i++){
            map.put(tangerine[i], map.getOrDefault(tangerine[i], 0)+1);
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int i : map.keySet()){
            list.add(map.get(i));
        }
        
        Collections.sort(list, Collections.reverseOrder());
        
        for(int i=0; i<list.size(); i++){
            if(k<=0) break;
            
            k -= list.get(i);
            answer++;
        }
        
        
        return answer;
    }
}