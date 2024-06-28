fun main() {
    val n = readLine()!!.toInt()
    val people = Array(n) {
        val (weight, height) = readLine()!!.split(" ").map { it.toInt() }
        Pair(weight, height)
    }

    val ranks = IntArray(n) { 1 }

    for (i in 0 until n) {
        for (j in 0 until n) {
            if (i != j && people[i].first < people[j].first && people[i].second < people[j].second) {
                ranks[i]++
            }
        }
    }

    for(i in 0 until ranks.size){
        print("${ranks[i]} ")
    }
}
