fun main (){
    val n = readln().toInt()
    val shirts = readln().split(" ").map { it.toInt() }

    val (t, p) = readln().split(" ").map { it.toInt() }

    var shirt = 0

    repeat(shirts.size){
        shirt += if(shirts[it] % t == 0){
            shirts[it] / t
        } else {
            shirts[it] / t + 1
        }
    }

    println(shirt)

    var penBundles = n / p
    var remainingPens = n % p

    println("$penBundles $remainingPens")

}