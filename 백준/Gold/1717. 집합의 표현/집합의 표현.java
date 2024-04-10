import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] parent;
    static int a, b;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }



        int isCheck;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(bf.readLine(), " ");
            isCheck = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if(isCheck == 1){
                if(find(a)==find(b)){
                    System.out.println("YES");
                }
                else{
                    System.out.println("NO");
                }
            }
            else{
                union(a, b);
            }
        }
    }

    static void union(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);

        parent[aRoot] = bRoot;
    }

    private static int find(int i) {
        if(parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    }
}