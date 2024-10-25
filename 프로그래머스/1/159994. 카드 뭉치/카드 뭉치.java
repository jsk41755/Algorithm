class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        
        int c1 = 0, c2 = 0;
        int cnt = 0;
        while(cnt < goal.length){
            if (c1 < cards1.length && goal[cnt].equals(cards1[c1])) {
                c1++;
                cnt++;
            } else if (c2 < cards2.length && goal[cnt].equals(cards2[c2])) {
                c2++;
                cnt++;
            } else {
                break;
            }
        }
        
        if(goal.length == c1+c2) answer = "Yes";
        else answer = "No";
        
        return answer;
    }
}