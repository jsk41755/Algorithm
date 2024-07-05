class Solution {
    fun solution(answers: IntArray): IntArray {
        var answer = intArrayOf()
        
        val firstPattern = intArrayOf(1, 2, 3, 4, 5)
        val secondPattern = intArrayOf(2, 1, 2, 3, 2, 4, 2, 5)
        val thirdPattern = intArrayOf(3, 3, 1, 1, 2, 2, 4, 4, 5, 5)

        val scores = intArrayOf(0, 0, 0)

        for (i in answers.indices) {
            if (answers[i] == firstPattern[i % firstPattern.size]) scores[0]++
            if (answers[i] == secondPattern[i % secondPattern.size]) scores[1]++
            if (answers[i] == thirdPattern[i % thirdPattern.size]) scores[2]++
        }
        
        val maxScore = scores.maxOrNull()
        
        for (i in scores.indices) {
            if (scores[i] == maxScore) answer += (i + 1)
        }
        
        
        return answer
    }
}