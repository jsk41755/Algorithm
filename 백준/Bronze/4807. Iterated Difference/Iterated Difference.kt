fun main() {
    var count = 0

    while (true) {
        val num = readln().toInt()
        if (num == 0) break

        val nums = readln().split(" ").map { it.toInt() }.toIntArray()
        count++
        var cnt = 0
        var flag = false

        while (true) {
            val newNums = IntArray(nums.size)

            if (nums.all { it == nums[0] }) {
                break
            }

            for (i in 0 until nums.size) {
                newNums[i] = if (i == nums.size - 1) {
                    Math.abs(nums[i] - nums[0])
                } else {
                    Math.abs(nums[i] - nums[i + 1])
                }
            }

            cnt++

            for (i in 0 until nums.size) {
                nums[i] = newNums[i]
            }

            if (newNums.all { it == newNums[0] }) {
                break
            }


            if (cnt >= 1000) {
                println("Case $count: not attained")
                flag = true
                break
            }



        }

        if (!flag) {
            println("Case $count: $cnt iterations")
        }
    }
}
