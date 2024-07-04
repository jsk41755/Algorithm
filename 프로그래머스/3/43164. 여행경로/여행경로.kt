import java.util.*

class Solution {
    lateinit var visited : BooleanArray
    val answer = mutableListOf<String>()

    fun solution(tickets: Array<Array<String>>): Array<String> {
        visited = BooleanArray(tickets.size)
        tickets.sortBy { it[1] }
        dfs("ICN", 0, tickets)

        return answer.toTypedArray()
    }

    val temp = mutableListOf<String>()
    
    fun dfs(now: String, cnt: Int, tickets: Array<Array<String>>) {
        if (cnt == tickets.size) {
            if (answer.isEmpty()) {
                answer.addAll(temp)
                answer.add(now)
            }
            return
        }

        for (i in tickets.indices) {
            if (tickets[i][0] == now && !visited[i]) {
                visited[i] = true
                temp.add(now)
                dfs(tickets[i][1], cnt + 1, tickets)
                visited[i] = false
                temp.removeAt(temp.lastIndex)
            }
        }
    }
}