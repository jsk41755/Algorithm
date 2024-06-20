fun main (){
    val (n, m) = readln().split(" ").map { it.toInt() }
    val trees = readln().split(" ").map { it.toInt() }.toIntArray()

    var left = 0;
    var right = trees.max()

    var result = 0;

    while(left <= right){
        val mid = (left + right) / 2
        var total : Long = 0

        repeat(trees.size) {
            if(trees[it] > mid){
                total += (trees[it] - mid)
            }
        }

        if(total < m){
            right = mid - 1
        } else {
            result = mid
            left = mid + 1
        }

    }

    println(result)

}