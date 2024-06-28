fun main(){
    val num = readLine()

    for(i in 1.. num!!.toInt()) {
        var sum = i
        val cntString = i.toString()

        for(k in 0 until cntString.length){
            sum = sum + cntString[k].digitToInt()
        }

        if (sum == num.toInt()){
            println(i)
            return
        }
    }

    print(0)
}