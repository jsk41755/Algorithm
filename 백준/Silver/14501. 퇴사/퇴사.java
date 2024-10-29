import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        int Case = sc.nextInt();
        int[] T = new int[Case+1];//소요 기간
        int[] P = new int[Case+1];//금액

        int[] dp = new int[Case+2];

        for(int i=1;i<=Case;i++) {
            T[i]=sc.nextInt();
            P[i]=sc.nextInt();
        }

        for(int i=1; i<=Case; i++){
            if(i+T[i] <= Case + 1){
                dp[i+T[i]] = Math.max(dp[i+T[i]], P[i] + dp[i]);
            }
            dp[i+1]=Math.max(dp[i+1],dp[i]);
        }
        System.out.println(dp[Case+1]);

        return;
    }
}
