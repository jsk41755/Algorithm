import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Node>[] list;
    static boolean[] visited;
    static int max = 0;
    static int node;

    public static class Node {
        int e;
        int cost;

        public Node(int e, int cost) {
            this.e = e;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        list = new ArrayList[n+1];

        for(int i=0; i<=n; i++) {
            list[i] = new ArrayList<>();
        }

        for(int i=0; i<n-1; i++) {
            String [] t = br.readLine().split(" ");
            int parent = Integer.parseInt(t[0]);
            int child = Integer.parseInt(t[1]);
            int weight = Integer.parseInt(t[2]);
            list[parent].add(new Node(child,weight));
            list[child].add(new Node(parent,weight));
        }

        for(int i=1; i<=n; i++){
            visited = new boolean[n + 1];
            dfs(i, 0);
        }

        System.out.println(max);
    }

    public static void dfs(int x, int len) {
        if(len > max) {
            max = len;
            node = x;
        }
        visited[x] = true;

        for(int i = 0; i < list[x].size(); i++) {
            Node n = list[x].get(i);
            if(!visited[n.e]) {
                dfs(n.e, n.cost + len);
                visited[n.e] = true;
            }
        }

    }
}