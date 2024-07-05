class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        var answer = n
        
        var sortedLost = lost.sortedArray()
        var sortedReserve = reserve.sortedArray()
        
        for(i in 0 until sortedReserve.size) {
            for(j in 0 until sortedLost.size) {
                if(sortedReserve[i] == sortedLost[j]){
                    sortedLost[j] = -999
                    sortedReserve[i] = -99
                    break
                }
            }
        }
        
        for(i in 0 until sortedReserve.size) {
            for(j in 0 until sortedLost.size) {
                if(sortedReserve[i] == sortedLost[j] || sortedReserve[i] - 1 == sortedLost[j] || sortedReserve[i] + 1 == sortedLost[j]){
                    sortedLost[j] = -999
                    sortedReserve[i] = -99
                    break
                }
            }
        }
        
        var cnt = 0
        
        for(i in sortedLost){
            if(i != -999) cnt++
        }
        
        answer -= cnt
        
        return answer
    }
}