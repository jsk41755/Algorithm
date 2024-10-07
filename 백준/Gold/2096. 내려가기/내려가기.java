import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int a1, a2, a3;
    static int b1, b2, b3;
    static int c1, c2, c3;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        int t1, t2, t3;

        for(int i=1;i<=n;i++)
        {
            st = new StringTokenizer(br.readLine());

            a1 = Integer.parseInt(st.nextToken());
            a2 = Integer.parseInt(st.nextToken());
            a3 = Integer.parseInt(st.nextToken());

            t1 = Math.max(b1, b2) + a1;
            t2 = Math.max(b1, Math.max(b2,b3)) + a2;
            t3 = Math.max(b2, b3) + a3;
            b1 = t1;
            b2 = t2;
            b3 = t3;

            t1 = Math.min(c1, c2) + a1;
            t2 = Math.min(c1, Math.min(c2,c3)) + a2;
            t3 = Math.min(c2, c3) + a3;
            c1 = t1;
            c2 = t2;
            c3 = t3;
        }

        System.out.println(Math.max(b1, Math.max(b2, b3)) +" " + Math.min(c1, Math.min(c2, c3)));
    }
}