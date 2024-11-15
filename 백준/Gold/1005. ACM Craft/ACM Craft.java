import java.io.*;
import java.util.*;

public class Main {
    static int n;   // 노드 갯수
    static int k;   // 간선 갯수
    static int[] d;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int tc = Integer.parseInt(br.readLine());

        for(int t=0; t<tc; t++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            d = new int[n+1];

            ArrayList<Integer>[] list = new ArrayList[n+1];
            int[] result = new int[n+1];

            for(int i=0; i<=n; i++){
                list[i] = new ArrayList<>();
                result[i] = -1;
            }

            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; i++)
                d[i] = Integer.parseInt(st.nextToken());

            for(int i=0; i<k; i++) {
                st = new StringTokenizer(br.readLine());

                int v1 = Integer.parseInt(st.nextToken());
                int v2 = Integer.parseInt(st.nextToken());

                list[v2].add(v1);
            }
            int w = Integer.parseInt(br.readLine());

            int res = dfs(list, d, result, w);

            System.out.println(res + d[w]);
        }
    }

    private static int dfs(ArrayList<Integer>[] list, int[] d, int[] result, int w) {
        if(result[w] == -1){
            for(int i=0; i<list[w].size(); i++){
                int prev = dfs(list, d, result, list[w].get(i));
                result[w] = Math.max(result[w], prev + d[list[w].get(i)]);
            }
        }

        result[w] = Math.max(result[w], 0);
        return result[w];
    }
}