import java.io.*;
import java.util.*;


public class Main {
	static public int n, m;
	static public int[] number;
	static public int[][] ans;
   
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
         
       n = Integer.parseInt(bf.readLine());
       
       number = new int[305];
       ans = new int[305][3];
       
       for(int i = 1; i<=n; i++) {
    	   number[i] = Integer.parseInt(bf.readLine());
       }
       
       if(n==1) {
    	   System.out.print(number[1]);
    	   return;
       }
       
       ans[1][1] = number[1];
       ans[1][2] = 0;
       ans[2][1] = number[2];
       ans[2][2] = number[1] + number[2];
       
       
       for(int i = 3; i<=n; i++) {
	    	   ans[i][1] = Math.max(ans[i-2][1], ans[i-2][2]) + number[i];
	    	   ans[i][2] = ans[i-1][1] + number[i];
       }
       
       System.out.print(Math.max(ans[n][1], ans[n][2]));
       

       
    }
    
   
}