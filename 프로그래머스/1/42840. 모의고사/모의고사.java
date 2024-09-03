import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] a = {1,2,3,4,5};
        int[] b = {2,1,2,3,2,4,2,5};
        int[] c = {3,3, 1,1, 2, 2, 4, 4, 5, 5};
        
        int[] ans = {0, 0, 0};
        
        for(int i=0; i<answers.length; i++){
            if(answers[i] == a[i%a.length]){
                ans[0]++;
            }
            if(answers[i] == b[i%b.length]){
                ans[1]++;
            }
            if(answers[i] == c[i%c.length]){
                ans[2]++;
            }
        }
        
        int max = -1;
        for(int i=0; i<ans.length; i++){
            if(max < ans[i]){
                max = ans[i];
            }
        }
        
        ArrayList<Integer> answer = new ArrayList<>();
        
        for(int i=0; i<ans.length; i++){
            if(max == ans[i]){
                answer.add(i+1);
            }
        }
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}