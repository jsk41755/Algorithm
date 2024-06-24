fun main() {
 var num = 0

 val list = mutableListOf<String>()
 for (k in 0 until 3) {
  val str = readln()
  list.add(str)
 }

 if(list[2]!!.toIntOrNull() != null){
  num = list[2]!!.toInt()
  num += 1
 } else if(list[1]!!.toIntOrNull() != null) {
  num = list[1]!!.toInt()
  num += 2
 } else {
  num = list[0]!!.toInt()
  num += 3
 }

 val result = when {
  num % 15 == 0 -> "FizzBuzz"
  num % 3 == 0 -> "Fizz"
  num % 5 == 0 -> "Buzz"
  else -> num.toString()
 }

 println(result)
}
