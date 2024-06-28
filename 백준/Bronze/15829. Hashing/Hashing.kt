fun main() {
    val l = readLine()!!.toInt()
    val alphabet: String = readLine()!!

    var sum: Long = 0
    var power: Long = 1
    val mod = 1234567891
    val base = 31

    for (i in 0 until l) {
        val charValue = alphabet[i] - 'a' + 1
        sum = (sum + (charValue * power) % mod) % mod
        power = (power * base) % mod
    }

    println(sum)
}
