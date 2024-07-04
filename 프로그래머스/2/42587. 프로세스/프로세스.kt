import java.util.*

data class Document(val priority: Int, val index: Int)

class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        val queue: Queue<Document> = LinkedList()
        
        for (i in priorities.indices) {
            queue.add(Document(priorities[i], i))
        }

        var printOrder = 0
        
        while (queue.isNotEmpty()) {
            val current = queue.poll()
            
            if (queue.any { it.priority > current.priority }) {
                queue.add(current)
            } else {
                printOrder++
                if (current.index == location) {
                    return printOrder
                }
            }
        }
        
        return -1
    }
}