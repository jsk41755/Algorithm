import java.util.*;

class Solution {
    
    
    public static class Pair{
        int a, b;
        
        public Pair(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
    
    ArrayList<Pair> list = new ArrayList<>();
    
    public void rec(int a, int b, int n){
        if(n == 1) {
            list.add(new Pair(a, b));
            return;
        }
        
        rec(a, 6-a-b, n-1);
        list.add(new Pair(a, b));
        rec(6-a-b, b, n-1);
    }

    
    public int[][] solution(int n) {
        int[][] answer = {};
        
        rec(1, 3, n);
        
        answer = new int[list.size()][2];
        
        for(int i=0; i<list.size(); i++){
            answer[i][0] = list.get(i).a;
            answer[i][1] = list.get(i).b;
        }
        
        
        return answer;
    }
}