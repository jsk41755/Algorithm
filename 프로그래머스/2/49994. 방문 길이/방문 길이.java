import java.util.*;

class Solution {
    
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, -1, 0, 1};
    boolean[][][] isVisit = new boolean[11][11][4];
    
    public int solution(String dirs) {
        int answer = 0;
        
        int x = 5;
        int y = 5;
        
        for(int i=0; i<dirs.length(); i++){
            int dir = 0;
            if(dirs.charAt(i) == 'U'){
                dir = 0;
            }
            else if(dirs.charAt(i) == 'D'){
                dir = 2;
            }
            else if(dirs.charAt(i) == 'L'){
                dir = 1;
            }
            else{
                dir = 3;
            }
            
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >= 0 && ny >= 0 && nx <= 10 && ny <= 10){
                int cntDir = (dir+2) % 4;
                if(!isVisit[y][x][dir] && !isVisit[ny][nx][cntDir]){
                    isVisit[y][x][dir] = true;
                    isVisit[ny][nx][cntDir] = true;
                    answer++;
                }
                x = nx;
                y = ny;
            }
        }
        
        
        return answer;
    }
}