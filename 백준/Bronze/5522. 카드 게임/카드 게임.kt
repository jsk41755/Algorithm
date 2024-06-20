fun main(){
    var sum = 0;

    for(i in 0 until 5){
        val num = readln().toInt()
        sum += num
    }

    println(sum)
}