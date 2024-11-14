import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M;
    static ArrayList<Integer>[] Map;
    static int[] Indegree;


    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Map = new ArrayList[N+1];
        Indegree = new int[N+1];

        for(int i=1;i<=N; i++){
            Map[i] = new ArrayList<>();
        }

        ArrayDeque<Integer> dq = new ArrayDeque<Integer>();

        int from, to;
        for(int i =1; i<=M; i++){
            st = new StringTokenizer(bf.readLine(), " ");
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            Map[from].add(to);
            Indegree[to]++;
        }

        for(int i = 1; i<=N; i++){
            if(Indegree[i] ==0){
                dq.addLast(i);
            }
        }

        int seq = 0;
        while (dq.isEmpty() == false){
            int now = dq.pollLast();
            seq++;

            if(seq == N){
                System.out.print(String.valueOf(now));
            }
            else {
                System.out.print(String.valueOf(now) + " ");
            }

            for(int next : Map[now]){
                if(Indegree[next] > 0){
                    Indegree[next]--;
                    if(Indegree[next] == 0){
                        dq.addLast(next);
                    }
                }
            }
        }
    }
}