import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    val num = reader.readLine().toInt()
    val array = IntArray(num)
    
    for(i in 0 until num){
        array[i] = reader.readLine().toInt()
    }
    
    array.sort()
    
    for(i in 0 until num){
        writer.write(array[i].toString())
        writer.newLine()
    }

    writer.flush()
    writer.close()
    reader.close()
}
