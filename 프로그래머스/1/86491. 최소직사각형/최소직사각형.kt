class Solution {
    fun solution(sizes: Array<IntArray>): Int {
        var answer: Int = 0
        
        val sortedArray = sizes.map { it.sortedArray()}
        
        var maxCol = 0
        var maxRow = 0
        
        for(i in 0 until sortedArray.size){
            if(sortedArray[i][0] > maxCol){
                maxCol = sortedArray[i][0]
            }
            if(sortedArray[i][1] > maxRow){
                maxRow = sortedArray[i][1]
            }
        }
        
        answer = maxCol * maxRow
        
        
        return answer
    }
}