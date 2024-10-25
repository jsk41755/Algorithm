import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String, Integer> map = new HashMap<>();
        
        // completion 배열의 이름을 카운트
        for (String name : completion) {
            map.put(name, map.getOrDefault(name, 0) + 1);
        }
        
        // participant 배열의 이름을 카운트하며 확인
        for (String name : participant) {
            if (!map.containsKey(name) || map.get(name) == 0) {
                answer = name;
                break;
            }
            map.put(name, map.get(name) - 1);
        }
        
        return answer;
    }
}
