import java.util.*;

class Solution {
    int[] arr;
    
    public int find(int a){
        if(a == arr[a]) return a;
        else return arr[a] = find(arr[a]);
    }
    
    public void union(int a, int b){
        int AA = find(a);
        int BB = find(b);
        
        arr[AA] = BB;
    }
    
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        arr = new int[n+1];
        
        for(int i=1; i<=n; i++){
            arr[i] = i;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && computers[i][j] == 1){
                    union(i+1, j+1);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            find(i+1);
        }
        
        HashSet<Integer> set = new HashSet<>();
        for(int i=0; i<n; i++){
            set.add(arr[i+1]);
        }
        
        answer += set.size();
        
        
        return answer;
    }
}