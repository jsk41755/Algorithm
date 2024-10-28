import java.util.*;

class Solution {
    public static class Pair{
        int a, b;
        
        public Pair(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
    
    
    public int solution(String[][] book_time) {
        int answer = 0;
        Pair[] arr = new Pair[book_time.length];
        
        for(int i=0; i<book_time.length; i++){
            int a = 0;
            int b = 0;
            for(int j=0; j<2; j++){
                String s = book_time[i][j];
                if(j == 0){
                    a = Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(3, 5));
                } else {
                    b = Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(3, 5)) + 9;
                }
            }
            arr[i] = new Pair(a, b);
        }
        
        //Arrays.sort(arr);
        int[] time = new int[2000];
        
        for(int i=0; i<arr.length; i++){
            for(int a = arr[i].a; a<= arr[i].b; a++){
                time[a]++;
            }
        }
        for(int i=0; i<2000; i++){
            answer = Math.max(answer, time[i]);   
        }
        
        
        return answer;
    }
}