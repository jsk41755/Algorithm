fun main() {
    val n = readLine()!!.toInt()
    var result = -1

    for (i in n / 5 downTo 0) {
        val remainder = n - i * 5
        if (remainder % 3 == 0) {
            result = i + remainder / 3
            break
        }
    }

    println(result)
}
