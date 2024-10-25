import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        
        double a = Math.sqrt(n);
        long b = (int)Math.sqrt(n);
        
        if(a-b>0){
            return -1;
        } else{
            answer = (b+1) * (b+1);
        }
        
        
        
        return answer;
    }
}