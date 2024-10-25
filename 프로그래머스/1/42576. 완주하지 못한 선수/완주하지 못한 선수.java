import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<completion.length; i++){
            map.put(completion[i], map.getOrDefault(completion[i], 0)+1);
        }
        
        for(String s: participant){
            if(!map.containsKey(s) || map.get(s) == 0){
                answer = s;
            } else {
                map.put(s, map.get(s) - 1);
            }
        }
        
        
        
        return answer;
    }
}