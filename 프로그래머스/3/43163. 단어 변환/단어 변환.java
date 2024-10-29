import java.util.*;

class Solution {
    boolean[] visit;
    int answer = 1987654321;
    int n = 0;
    String[] word;
    
    public void dfs(String begin, String target, int cnt){
        if(begin.equals(target)){
            answer = Math.min(answer, cnt);
            return;
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            if(!visit[i]){
                int a = 0;
                for(int j=0; j<word[i].length(); j++){
                    if(word[i].charAt(j) == begin.charAt(j)) a++;
                }
                
                if(word[i].length() == a + 1){
                    list.add(i);
                    visit[i] = true;
                }
            }
        }
        
        for(int i=0; i<list.size(); i++){
            System.out.println(word[list.get(i)] + " " + (cnt+1));
            dfs(word[list.get(i)], target, cnt+1);
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        n = words.length;
        visit = new boolean[words.length];
        word = words;
        
        dfs(begin, target, 0);
        
        if(answer == 1987654321) answer = 0;
        
        return answer;
    }
}