import java.util.*

class Solution {
    fun solution(n: Int, edge: Array<IntArray>): Int {
        var answer = 0
        
        var graph = Array(n+1) { mutableListOf<Int>()}
        for(e in edge){
            graph[e[0]].add(e[1])
            graph[e[1]].add(e[0])
        }
        
        val que: Queue<Int> = LinkedList()
        val visited = IntArray(n+1) { -1 }
        
        que.offer(1)
        visited[1] = 0
        
        while(que.isNotEmpty()) {
            val node = que.poll()
            for(n in graph[node]) {
                if(visited[n] == -1){
                    visited[n] = visited[node] + 1
                    que.offer(n)
                }
            }
        }
        
        val maxDistance = visited.maxOrNull()!!    
        
        for(i in visited){
            if(maxDistance == i){
                answer++
            }
        }
        
        return answer
    }
}