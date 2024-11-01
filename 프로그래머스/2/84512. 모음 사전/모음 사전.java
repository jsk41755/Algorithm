import java.util.*;

class Solution {
    char[] aeiou = {'A', 'E', 'I', 'O', 'U'};
    String w = "";
    int cnt = -1;
    int answer = 0;
    
    public void dfs(String s) {
        
        if(s.length() > 5) return;
        cnt++;
        
        if(s.equals(w)){
            answer = cnt;
            return;
        }
        
        
        for(int i=0; i<5; i++){
            dfs(s + aeiou[i]);
        }
    }
    
    public int solution(String word) {
        w = word;
        
        dfs("");
        
        return answer;
    }
}