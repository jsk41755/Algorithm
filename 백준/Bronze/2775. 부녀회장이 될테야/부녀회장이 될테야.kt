fun main(){
    val testCase = readLine()!!.toInt()

    val APT = Array(15) { IntArray(15)}

    for(i in 0 until 15){
        APT[i][1] = 1
        APT[0][i] = i
    }

    for(i in 1 until 15){
        for (j in 2 until 15) {
            APT[i][j] = APT[i][j-1] + APT[i-1][j]
        }
    }

    for (i in 0 until testCase){
        val k = readLine()!!.toInt()
        val n = readLine()!!.toInt()
        println(APT[k][n])
    }
}