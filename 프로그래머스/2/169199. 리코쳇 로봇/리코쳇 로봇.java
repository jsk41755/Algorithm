import java.util.*;

class Solution {
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    
    char[][] arr;
    boolean[][] isVisit;
    int[][] aa;
    
    
    int p, k;
    
    public static class Pair{
        int y, x;

        public Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    
    public int solution(String[] board) {
        int answer = -1;
        int n = board.length;
        int m = board[0].length();
        
        ArrayDeque<Pair> que = new ArrayDeque<>();
        
        arr = new char[n][m];
        isVisit = new boolean[n][m];
        aa = new int[n][m];
        
        
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[i].length(); j++){
                arr[i][j] = board[i].charAt(j);
                
                if(arr[i][j] == 'R') {
                    que.addLast(new Pair(i, j));
                    isVisit[i][j] = true;
                }
                
                if(arr[i][j] == 'G') {
                    p = i;
                    k = j;
                }
            }
        }
        
        while (!que.isEmpty()) {
            int x = que.peek().x;
            int y = que.peek().y;
            que.removeFirst();

            if (x == k && y == p) {
                answer = aa[y][x];
                break;
            }

            for (int i = 0; i < 4; i++) {
                int ax = x + dx[i];
                int ay = y + dy[i];

                while (ax >= 0 && ax < m && ay >= 0 && ay < n && arr[ay][ax] != 'D') {
                    ax += dx[i];
                    ay += dy[i];
                }

                ax -= dx[i];
                ay -= dy[i];

                if (ax >= 0 && ax < m && ay >= 0 && ay < n && arr[ay][ax] != 'D' && !isVisit[ay][ax]) {
                    aa[ay][ax] = aa[y][x] + 1;
                    isVisit[ay][ax] = true;
                    que.addLast(new Pair(ay, ax));
                }
            }
        }  
        
        return answer;
    }
}

