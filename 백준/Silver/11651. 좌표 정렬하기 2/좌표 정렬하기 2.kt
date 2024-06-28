fun main(){
    val n = readLine()!!.toInt()

    val points = Array(n){
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        Pair(x, y)
    }

    points.sortWith(compareBy({it.second}, {it.first}))

    points.forEach {
        println("${it.first} ${it.second}")
    }
}