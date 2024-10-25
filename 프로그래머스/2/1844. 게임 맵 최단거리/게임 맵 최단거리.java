import java.util.*;

class Solution {
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    
    private static class Pair{
        int r, c;
        public Pair(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
    
    boolean[][] isVisit;
    int[][] arr;
    
    public int solution(int[][] maps) {
        int answer = 0;
        
        int n = maps.length;
        int m = maps[0].length;
        
        isVisit = new boolean[n][m];
        arr = new int[n][m];
        
        ArrayDeque<Pair> que = new ArrayDeque<>();
        isVisit[0][0] = true;
        arr[0][0] = 1;
        
        que.addLast(new Pair(0,0));
        
        while(!que.isEmpty()){
            int y = que.peekFirst().r;
            int x = que.peekFirst().c;
            que.removeFirst();
            
            for(int i=0; i<4; i++){
                int ax = x+ dx[i];
                int ay = y+ dy[i];
                
                if(ax>=0 && ax<m && ay>=0 && ay<n){
                    if(!isVisit[ay][ax] && maps[ay][ax] != 0){
                        arr[ay][ax] = arr[y][x] + 1;
                        isVisit[ay][ax] = true;
                        que.addLast(new Pair(ay, ax));
                    }
                }
            }
        }
        
        answer = arr[n-1][m-1];
        
        if(answer == 0) return -1;
        
        return answer;
    }
}