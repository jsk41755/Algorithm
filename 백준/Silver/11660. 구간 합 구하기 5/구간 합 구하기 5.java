import java.io.*;
import java.util.*;

import javax.sql.rowset.spi.SyncResolver;


public class Main {
	static public int n, m, x1, x2, y1, y2;
	static public int[][] dp, number;
	static public int ans;
   
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");
         
       n = Integer.parseInt(st.nextToken());
       m = Integer.parseInt(st.nextToken());
       
       number = new int[n+1][n+1];
       dp = new int[n+1][n+1];
       
       for(int i = 1; i<=n; i++) {
    	   st = new StringTokenizer(bf.readLine(), " ");
	    	   for(int j=1; j<=n; j++) {
	    		   number[i][j] = Integer.parseInt(st.nextToken());
	    	   }
       }
       
       for(int i = 1; i<=n; i++) {
	    	   for(int j=1; j<=n; j++) {
	    		  dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + number[i][j];
	    	   }
       }
       
       for(int a=1; a<=m; a++) {
    	   st = new StringTokenizer(bf.readLine(), " ");
    	   x1 = Integer.parseInt(st.nextToken());
    	   y1 = Integer.parseInt(st.nextToken());
    	   
    	   x2 = Integer.parseInt(st.nextToken());
    	   y2 = Integer.parseInt(st.nextToken());
    	   
    	   ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
    	   System.out.println(ans);
    	   ans = 0;
       }
       

       
    }
    
   
}