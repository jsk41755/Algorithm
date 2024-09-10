import java.util.*

class Solution {
    fun solution(n: Int, k: Int, cmd: Array<String>): String {
        var cursor = k
        var size = n
        val removeStack = Stack<Int>()

        cmd.forEach {
            when (it[0]) {
                'U' -> {
                    val step = it.split(" ")[1].toInt()
                    cursor -= step
                }
                'D' -> {
                    val step = it.split(" ")[1].toInt()
                    cursor += step
                }
                'C' -> {
                    removeStack.push(cursor)
                    size -= 1
                    if (cursor == size) cursor--
                }
                else -> {
                    val comebackRow = removeStack.pop()
                    size += 1
                    if (comebackRow <= cursor) cursor++
                }
            }
        }

        val answer = StringBuilder()
        for (i in 0 until size) answer.append('O')
        
        while (removeStack.isNotEmpty()) {
            val removedRow = removeStack.pop()
            answer.insert(removedRow, 'X')
        }

        return answer.toString()
    }
}