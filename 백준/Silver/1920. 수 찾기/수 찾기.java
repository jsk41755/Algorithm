import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int[] A, B;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        
        A = new int[N];
        
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        for(int i=0; i<N; i++) {
        	A[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(A);
        
        M = Integer.parseInt(br.readLine());
        
        B = new int[M];
        
        st = new StringTokenizer(br.readLine(), " ");
        
        
        for(int i=0; i<M; i++) {
        	B[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i=0; i<M; i++) {
        	boolean find = false;
        	int start = 0;
        	int end = A.length -1;
        	while(start <= end) {
        		int mid_index = (start+end)/2;
        		if(A[mid_index] > B[i]) {
        			end = mid_index -1;
        		}
        		else if(A[mid_index] < B[i]) {
        			start = mid_index + 1;
        		}
        		else {
        			find = true;
        			break;
        		}
        	}
        	if(find) {
        		System.out.println(1);
        	}else {
        		System.out.println(0);
        	}
        }
        
    }

}