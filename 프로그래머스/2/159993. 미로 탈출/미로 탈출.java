import java.util.*;

class Solution {    
    
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    
    public static class Pair{
        int x, y;
        
        public Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    
    public int solution(String[] maps) {
        ArrayDeque<Pair> que = new ArrayDeque<>();
        
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length();
        
        int[][] arr = new int[n][m];
        boolean[][] visit = new boolean[n][m];
        boolean[][] visit2 = new boolean[n][m];
        
        int sy = 0, sx = 0;
        int ly = 0, lx = 0;
        int ey = 0, ex = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maps[i].charAt(j) == 'X') arr[i][j] = -1;
                else if(maps[i].charAt(j) == 'S'){
                    sy = i;
                    sx = j;
                }
                else if(maps[i].charAt(j) == 'L'){
                    ly = i;
                    lx = j;
                }
                else if(maps[i].charAt(j) == 'E'){
                    ey = i;
                    ex = j;
                }
            }
        }
        
        que.addLast(new Pair(sy, sx));
        visit[sy][sx] = true;
        
        while(!que.isEmpty()){
            int x = que.peekFirst().x;
            int y = que.peekFirst().y;
            que.removeFirst();
            
            for(int i=0; i<4; i++){
                int ax = x + dx[i];
                int ay = y + dy[i];
                
                if(ax>=0 && ax<m && ay>=0 && ay<n){
                    if(!visit[ay][ax] && arr[ay][ax] != -1){
                        visit[ay][ax] = true;
                        arr[ay][ax] = arr[y][x] + 1;
                        que.addLast(new Pair(ay, ax));
                    }
                }
            }
        }
        
        while(!que.isEmpty()){
            que.removeFirst();
        }
        
        if(arr[ly][lx] == 0){
            return -1;
        }
        
        int le = arr[ly][lx];
        System.out.println(le);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(maps[i].charAt(j) == 'X') arr[i][j] = -1;
                else arr[i][j] = 0;
            }
        }
        
        que.addLast(new Pair(ey, ex));
        visit2[ey][ex] = true;
        
        while(!que.isEmpty()){
            int x = que.peekFirst().x;
            int y = que.peekFirst().y;
            que.removeFirst();
            
            for(int i=0; i<4; i++){
                int ax = x + dx[i];
                int ay = y + dy[i];
                
                if(ax>=0 && ax<m && ay>=0 && ay<n){
                    if(!visit2[ay][ax] && arr[ay][ax] != -1){
                        visit2[ay][ax] = true;
                        arr[ay][ax] = arr[y][x] + 1;
                        que.addLast(new Pair(ay, ax));
                    }
                }
            }
        }
        
        if(arr[ly][lx] == 0){
            return -1;
        }
        
        int ee = arr[ly][lx];
        
        answer = le + ee;
        
        return answer;
    }
}