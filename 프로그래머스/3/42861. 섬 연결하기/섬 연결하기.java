import java.util.*;

class Solution {
    int[] arr;
    
    public int Find(int i){
        if(arr[i] == i) return i;
        else return arr[i] = Find(arr[i]);
    }

    public void Union(int a, int b){
            int aRoot = Find(a);
            int bRoot = Find(b);

            arr[aRoot] = bRoot;
        }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        arr = new int[n+1];
        
        Arrays.sort(costs, (o1, o2) -> o1[2] - o2[2]);
        
        for(int i=1; i<=n; i++){
            arr[i] = i;
        }
        
        for(int i=0; i<costs.length; i++){
            if(Find(costs[i][0]) != Find(costs[i][1])){
                Union(costs[i][0], costs[i][1]);
                answer += costs[i][2];
            }
        }
        
        
        return answer;
    }
}