import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        HashMap<String, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> Find = new HashMap<>();
        
        int cnt= 0;
        for(int i=0; i<id_list.length; i++){
            map.put(id_list[i], cnt++);
        }
        
         boolean[][] arr = new boolean[id_list.length][id_list.length];
        
        for (String rep : report) {
            String[] parts = rep.split(" ");
            String a = parts[0];
            String b = parts[1];
            
            int reporterIdx = map.get(a);
            int reportedIdx = map.get(b);
            
            if (!arr[reporterIdx][reportedIdx]) {
                arr[reporterIdx][reportedIdx] = true;
                Find.put(reportedIdx, Find.getOrDefault(reportedIdx, 0) + 1);
            }
        }
        
        for (int i = 0; i < id_list.length; i++) {
            for (int j = 0; j < id_list.length; j++) {
                if (arr[i][j] && Find.getOrDefault(j, 0) >= k) {
                    answer[i]++;
                }
            }
        }
        
        
        return answer;
    }
}