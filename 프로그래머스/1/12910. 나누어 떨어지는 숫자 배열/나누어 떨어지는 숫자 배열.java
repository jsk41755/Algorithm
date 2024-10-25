import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {};
        ArrayList<Integer> a = new ArrayList<>();
        
        for(int i=0; i<arr.length; i++){
            if(arr[i] % divisor == 0){
                a.add(arr[i]);
            }
        }
        
        
        answer = a.stream()
	    .mapToInt(Integer::intValue)
    	.toArray();
        
        Arrays.sort(answer);
        
        if(answer.length == 0){
            int[] as = {-1};
            return  as;
        }
        
        return answer;
    }
}