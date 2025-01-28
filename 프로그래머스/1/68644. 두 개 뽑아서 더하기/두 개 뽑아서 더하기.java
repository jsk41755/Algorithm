import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        Set<Integer> aa = new HashSet<>();
        
        for(int i=0; i<numbers.length; i++){
            for(int j=i+1; j<numbers.length; j++){
                aa.add(numbers[i]+numbers[j]);
            }
        }
        
        int[] answer = new int[aa.size()];
        
        int cnt = 0;
        for(int v:aa){
            answer[cnt++] = v;
        }
        
        Arrays.sort(answer);
        
        
        return answer;
    }
}