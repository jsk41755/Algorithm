class Solution {
    public int solution(String s) {
        int answer = 0;
        
        char c = s.charAt(0);
        int a = 1, b = 0;
        
        String k = "";
        k += c;
        
        for(int i=1; i<s.length(); i++){
            if(a == 0) c = s.charAt(i);
            
            if(c != s.charAt(i)){
                b++;
            } else {
                a++;
            }
            k += s.charAt(i);
            
            if(a == b){
                System.out.println(k);
                answer++;
                k = "";
                a = 0;
                b = 0;
            }
        }
        
        if(a>0) answer++;
        
        return answer;
    }
}