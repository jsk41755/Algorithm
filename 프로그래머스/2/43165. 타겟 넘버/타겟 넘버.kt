class Solution {
    
    var answer = 0
    
    fun findTargetNumberWays(numbers: IntArray, target: Int): Int {
    return dfs(numbers, target, 0, 0)
}

    fun dfs(numbers: IntArray, target: Int, index: Int, sum: Int): Int {
        if (index == numbers.size) {
            return if (sum == target) 1 else 0
        }

        return dfs(numbers, target, index + 1, sum + numbers[index]) +
               dfs(numbers, target, index + 1, sum - numbers[index])
    }
    
    fun solution(numbers: IntArray, target: Int): Int {
        
        val result = findTargetNumberWays(numbers, target)
        
        return result
    }
}