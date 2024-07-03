class Solution {
    fun solution(arr: Array<IntArray>): Int {
    
        
        var answer: Int = 0
        
        val rowSize = arr[0].size
        val colSize = arr.size

        var flag = true

        for (i in 0 until rowSize) {
            for (j in 0 until colSize) {
                if(arr[i][j] != arr[j][i]){
                    flag = false
                    break
                }
            }
        }

        if (flag){
            answer = 1
        } else {
            answer = 0
        }
        
        return answer
    }
}