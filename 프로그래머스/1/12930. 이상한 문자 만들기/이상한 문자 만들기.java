import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == ' ') {
                cnt = 0;
                answer += ' ';
                continue;
            }
            
            if(cnt % 2 == 0){
                char c = Character.toUpperCase(s.charAt(i));
                answer += c;
                cnt++;
            } else {
                char c = Character.toLowerCase(s.charAt(i));
                answer += c;
                cnt++;
            }
        }
        
        return answer;
    }
}