fun main() {
    val tc = readLine()!!.toInt()

    repeat(tc) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val documents = readLine()!!.split(" ").mapIndexed { index, priority -> Pair(index, priority.toInt()) }.toMutableList()

        var printOrder = 0

        while (documents.isNotEmpty()) {
            val current = documents.removeAt(0)
            if (documents.any { it.second > current.second }) {
                documents.add(current)
            } else {
                printOrder++
                if (current.first == m) {
                    println(printOrder)
                    break
                }
            }
        }
    }
}
