import java.util.*;

class Solution {
    boolean[] isVisit = new boolean[9999999];
    int answer = 0;
    int length = 0;
    String number = "";
    
    public boolean isPrime(int num){
        
        System.out.println(num);
        if(num < 2) return false;
        
        if(num == 2) return true;
        
        for(int i=2; i<num; i++){
            if(num % i == 0){
                return false;
            }
        }
        
        return true;
    }
    
    public void rec(String s, int cnt, boolean[] visit){
        
        if(cnt > 0){
            if(!isVisit[Integer.parseInt(s)]){
                isVisit[Integer.parseInt(s)] = true;
                boolean a = isPrime(Integer.parseInt(s));
                if(a) answer++;
            }
        }
        
        if(cnt < length){
            for(int i=0; i<length; i++){
                if(visit[i]){
                    continue;
                }else{
                    visit[i] = true;
                    rec(s+number.charAt(i), cnt+1, visit);
                    visit[i] = false;
                }
            }
        }
    }
    
    public int solution(String numbers) {
        length = numbers.length();
        number = numbers;
        boolean[] visit = new boolean[numbers.length()];
        
        rec("", 0, visit);
        
        return answer;
    }
}