class Solution {
    fun solution(numbers: IntArray): String {
        
        val sortedNumbers = numbers.map { it.toString() }
                                   .sortedWith(Comparator { a, b ->
                                       (b + a).compareTo(a + b)
                                   })
                                   
        val answer = sortedNumbers.joinToString("")
        
        return if (answer[0] == '0') "0" else answer
    }
}