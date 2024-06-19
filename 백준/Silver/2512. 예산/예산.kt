fun main() {
    val n = readln().toInt()

    val v = mutableListOf<Int>()

    var l = 0
    var r = 0

    val nums = readln().split(" ").map { it.toInt() }
    for (num in nums) {
        v.add(num)
        r = maxOf(r, num)
    }

    val m = readln().toInt()

    var result = 0
    var sum: Int

    while (l <= r) {
        sum = 0
        val mid = (l + r) / 2

        for (i in 0 until n) {
            sum += minOf(v[i], mid)
        }

        if (m >= sum) {
            result = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    println(result)
}