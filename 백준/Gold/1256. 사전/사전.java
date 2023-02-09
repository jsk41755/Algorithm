import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static int n,m,k;
    static int[][] dp;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        setDP();
        getStr();

    }

    static void setDP() {
        dp = new int[201][201];
        dp[0][0] = 0;
        for(int i=1;i<=100;i++) {
            dp[i][0] = dp[0][i] = 1;
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if(dp[i][j] > 1000000000) dp[i][j] = 1000000000;
            }
        }
    }

    static void getStr() {
        int acnt = n;
        int zcnt = m;
        int as;

        if(k > dp[n][m]) {
            System.out.print(-1);
            return;
        }

        for(int i=0;i<n+m;i++) {

            if(acnt == 0) {
                System.out.print("z");
                zcnt--;
                continue;
            }
            else if(zcnt == 0) {
                System.out.print("a");
                acnt--;
                continue;
            }

            as = dp[acnt-1][zcnt];
            if( k <= as) {
                System.out.print("a");
                acnt--;
            }
            else {
                k -= as;
                System.out.print("z");
                zcnt--;
            }
        }

    }
}