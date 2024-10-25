import java.util.*;

class Solution {
    int t;
    int answer = 0;
    
    public void dfs(int[] numbers, int idx, boolean b, int sum){
        if(b){
            sum -= numbers[idx];
        } else {
            sum += numbers[idx];
        }
        
        if(idx == numbers.length - 1){
            if(sum == t){
                answer++;
            }
            return;
        } else {
            dfs(numbers, idx+1, !b, sum);
            dfs(numbers, idx+1, b, sum);
        }
    }
    
    public int solution(int[] numbers, int target) {
        t = target;
        
        dfs(numbers, 0, false, 0);
        dfs(numbers, 0, true, 0);
        
        return answer;
    }
}