class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int[][] arr = new int[n+1][m+1];
        
        for(int i=0; i<puddles.length; i++){
            arr[puddles[i][1]][puddles[i][0]] = -1;
        }
        arr[1][1] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i][j] != -1){
                    if(i==1 && j == 1) continue;
                    arr[i][j] = (arr[i][j-1] % 1000000007 + arr[i-1][j] % 1000000007)  % 1000000007;
                } else {
                    if(i==1 && j == 1) continue;
                    arr[i][j] = 0;
                }
            }
        }
        
        answer = arr[n][m];
        
        return answer;
    }
}