import java.io.*;
import java.util.*;


public class Main {
	static public int n;
	static public int[][] tri, D;
	static public int ans;
   
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
       n = Integer.parseInt(bf.readLine());
       
       tri = new int[n+1+1][n+1+1];
       D = new int[n+1+1][n+1+1];
       
       for(int i=1; i<=n; i++) {
    	   st = new StringTokenizer(bf.readLine(), " ");
    	   for(int j=1; j<=i; j++) {
    		   tri[i][j] = Integer.parseInt(st.nextToken());
    	   }
       }
       
       for(int i = 1; i<=n; i++) {
    	   for(int j=1; j<=i; j++) {
    		   D[i][j] = tri[i][j] + Math.max(D[i-1][j-1],D[i-1][j]);
    	   }
       }
       
       for(int i = 1; i<=n; i++) {
    		   ans = Integer.max(ans,D[n][i]);
       }
       
       System.out.print(ans);
       
    }
    
   
}