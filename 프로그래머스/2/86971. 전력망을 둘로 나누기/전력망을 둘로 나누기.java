import java.util.*;

class Solution {
    ArrayList<Integer>[] list;
    
    public int dfs(int idx, boolean[] visit){
        int cnt = 1;
        
        for(int i : list[idx]){
            if(!visit[i]){
                visit[i] = true;
                cnt += dfs(i, visit);
                visit[i] = false;
            }
        }
        
        return cnt;
    }
    
    public int solution(int n, int[][] wires) {
        list = new ArrayList[n+1];
        int answer = 99999;
        
        for(int i=1; i<=n; i++){
            list[i] = new ArrayList<>();
        }
        
        for(int i=0; i<wires.length; i++){
            int a = wires[i][0];
            int b = wires[i][1];
            
            list[a].add(b);
            list[b].add(a);
        }
        
        for(int i=0; i<wires.length; i++){
            int a = wires[i][0];
            int b = wires[i][1];
            
            list[a].remove(Integer.valueOf(b));
            list[b].remove(Integer.valueOf(a));
            
            boolean[] visit = new boolean[n+1];
            visit[1] = true;
            int cnt = dfs(1, visit);
            
            int diff = Math.abs(cnt - (n - cnt));
            answer = Math.min(answer, diff);
            
            list[a].add(b);
            list[b].add(a);
        }
        
        return answer;
    }
}