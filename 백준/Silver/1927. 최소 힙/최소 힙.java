import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static int n, num;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(bf.readLine());

        PriorityQueue<Integer> mnq = new PriorityQueue<>();
        Queue<Integer> queue = new LinkedList<>();

        for(int i=0; i<n; i++){
            num = Integer.parseInt(bf.readLine());
            if(num != 0){
                mnq.add(num);
            }
            else{
                if(mnq.peek() == null){
                    queue.add(0);
                }

                else{
                    queue.add(mnq.poll());
                }

            }
        }

        int num = queue.size();


        for(int i=0; i<= num; i++){
            if(!queue.isEmpty())
                System.out.println(queue.poll());
        }


        /*
        mnq.add(1);
        mnq.peek();
        mnq.poll();*/
    }
}
