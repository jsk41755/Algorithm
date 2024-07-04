class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1
        val map : MutableMap<String, Int> = mutableMapOf()
        
        for(i in 0 until clothes.size){
            val currentValue = map.getOrDefault(clothes[i][1], 0)
            map[clothes[i][1]] = currentValue + 1
        }
        
        for (count in map.values) {
        answer *= (count + 1)
        }
        
        
        return answer - 1
    }
}