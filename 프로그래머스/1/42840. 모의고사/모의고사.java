import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] a = {1, 2, 3, 4, 5};
        int[] b = {2, 1, 2, 3, 2, 4, 2, 5,};
        int[] c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int aa = 0, bb = 0, cc = 0;
        
        int m = 0;
        
        for(int i=0; i<answers.length; i++){
            if(answers[i] == a[i%a.length]) aa++;
            if(answers[i] == b[i%b.length]) bb++;
            if(answers[i] == c[i%c.length]) cc++;
            
            m = Math.max(m, aa);
            m = Math.max(m, bb);
            m = Math.max(m, cc);
            
        }
        
        int cnt = 0;
        
        if(aa == m){
            cnt++;
        }
        
        if(bb == m){
            cnt++;
        }
        
        if(cc == m){
            cnt++;
        }
        
        int[] answer = new int[cnt];
        cnt = 0;
        if(aa == m){
            answer[cnt++] = 1;
        }
        
        if(bb == m){
            answer[cnt++] = 2;
        }
        
        if(cc == m){
            answer[cnt++] = 3;
        }
        
        return answer;
    }
}