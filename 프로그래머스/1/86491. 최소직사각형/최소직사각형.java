import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        for(int i=0; i<sizes.length; i++){
            Arrays.sort(sizes[i]);
        }
        
        int n = 0, m = 0;
        
        for(int i=0; i<sizes.length; i++){
            n = Math.max(n, sizes[i][0]);
            m = Math.max(m, sizes[i][1]);
        }
        
        answer = n * m;
        
        return answer;
    }
}