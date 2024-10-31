import java.util.*;

class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;

        Arrays.sort(A);
        ArrayList<Integer> list = new ArrayList<>();
        
        for(int i=0; i<B.length; i++){
            list.add(B[i]);
        }
        
        Collections.sort(list, Collections.reverseOrder());
        
        for(int i=0; i<A.length; i++){
            answer += A[i] * list.get(i);
        }
        

        return answer;
    }
}