class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf()
        
        var col = (brown - 2) / 2 - 2
        var row = 1
        
        var ans = 0
        
        while(ans != yellow){
            ans = col * row
            
            if(ans != yellow){
                col--
                row++
            }
        }
        
        answer += col + 2
        answer += row + 2
        
        
        return answer
    }
}