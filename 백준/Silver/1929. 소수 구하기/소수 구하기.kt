fun main() {
    val (m, n) = readLine()!!.split(" ").map { it.toInt() }
    val isPrime = BooleanArray(n + 1) { true }

    isPrime[0] = false
    isPrime[1] = false

    for (i in 2..n) {
        if (isPrime[i]) {
            var multiple = i * 2
            while (multiple <= n) {
                isPrime[multiple] = false
                multiple += i
            }
        }
    }

    for (i in m..n) {
        if (isPrime[i]) {
            println(i)
        }
    }
}
