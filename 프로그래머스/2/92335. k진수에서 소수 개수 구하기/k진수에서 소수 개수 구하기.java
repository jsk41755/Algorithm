import java.util.*;


class Solution {
    public boolean isPrime(long p){
        long num = (long)Math.sqrt(p);
        
        if(p == 1) return false;
        if(p == 2) return true;
        
        for(long i=2; i<= num; i++){
            if (p % i == 0) return false;
        }
        return true;
    }
    
    
    public int solution(int n, int k) {
        int answer = 0;
        
        String s = Integer.toString(n, k);
        s+='-';
        String tmp = "";
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) > '0' && s.charAt(i) <= '9'){
                tmp += s.charAt(i);
            } 
            else if(tmp.length() > 0){
                boolean flag = isPrime(Long.parseLong(tmp));
                if(flag) answer++;
                System.out.println(tmp);
                tmp = "";
            } 
            else {
                tmp = "";
            }
        }
        
        return answer;
    }
}