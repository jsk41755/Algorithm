import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        Arrays.sort(times);
        long l = 0, r = times[times.length-1] * (long)n;
        
        while(l <= r){
            long mid = (l+r) / 2;
            long sum = 0;
            
            for(int i=0; i<times.length; i++){
                sum += mid / times[i];
            }
            
            if(sum < n){
                l = mid + 1;
            } else{
                answer = mid;
                r = mid - 1;
            }
        }
        
        
        return answer;
    }
}