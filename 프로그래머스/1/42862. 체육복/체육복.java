import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        
        for(int i=0; i<lost.length; i++){
            arr.add(lost[i]);
        }
        
        Collections.sort(arr);
        Arrays.sort(reserve);
        
        for(int i=0; i<reserve.length; i++){
            for(int j=0; j<arr.size(); j++){
                if(reserve[i] == arr.get(j)){
                    reserve[i] = -1;
                    arr.remove(arr.get(j));
                }
            }
        }
        
        for(int i=0; i<reserve.length; i++){
            for(int j=0; j<arr.size(); j++){
                if(reserve[i]-1 == arr.get(j) || reserve[i] + 1== arr.get(j)){
                    reserve[i] = -1;
                    arr.remove(arr.get(j));
                }
            }
        }
        
        int k = arr.size();
        answer = n - k;
        
        return answer;
    }
}