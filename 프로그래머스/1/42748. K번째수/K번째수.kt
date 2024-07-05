class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = intArrayOf()
        
        for(i in 0 until commands.size) {
            
            val rArray = array.sliceArray(commands[i][0] - 1..commands[i][1] - 1)
            
            var sArray = rArray.sortedArray()
            
            answer += sArray[commands[i][2]-1]
            
        }
        
        return answer
    }
}