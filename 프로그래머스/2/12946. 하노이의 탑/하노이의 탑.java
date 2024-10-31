import java.util.*;

class Solution {
    ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    
    public void rec(int a, int b, int n){
        ArrayList<Integer> li = new ArrayList<>();
        
        if(n==1){
            li.add(a);
            li.add(b);
            list.add(li);
            return;
        }
        
        rec(a, 6-a-b, n-1);
        li.add(a);
        li.add(b);
        list.add(li);
        rec(6-a-b, b, n-1);
        
    }
    
    
    public int[][] solution(int n) {
        
        rec(1, 3, n);
        
        int[][] answer = new int[list.size()][2];
        
        for(int i=0; i<list.size(); i++){
            for(int j=0; j<2; j++){
                answer[i][j] = list.get(i).get(j);
            }
        }
        
        return answer;
    }
}