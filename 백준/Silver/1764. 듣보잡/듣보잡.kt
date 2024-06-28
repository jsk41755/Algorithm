fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }

    val listen = mutableSetOf<String>()
    val see = mutableSetOf<String>()

    repeat(n){
        listen.add(readLine()!!)
    }

    repeat(m){
        see.add(readLine()!!)
    }

    val result = see.intersect(listen).sorted()
    println(result.size)
    result.forEach{
        println(it)
    }
}
