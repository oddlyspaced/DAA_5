class TSPKT {

    private val G = arrayOf(
        arrayOf(0, 10, 15, 20),
        arrayOf(5, 0, 9, 10),
        arrayOf(6, 13, 0, 12),
        arrayOf(8, 8, 9, 0),
    )

//    private val G = arrayOf(
//        arrayOf(0, 20, 30, 10, 11),
//        arrayOf(15, 0, 16, 4, 2),
//        arrayOf(3, 5, 0, 2, 4),
//        arrayOf(19, 6, 18, 0, 3),
//        arrayOf(16, 4,7, 17, 0)
//    )

    fun without(all: ArrayList<Int>, rem: Int): ArrayList<Int> {
        val copy = all.clone() as ArrayList<Int>
        copy.remove(rem)
        return copy
    }

    fun g(i: Int, S: ArrayList<Int>): Int {

        if (S.size == 0) {
            return G[i][0]
        }

        var min = 9999
        for (k in S) {
            val temp = G[i][k] + g(k, without(S, k))
            if (min > temp) {
                min = temp
            }
        }
        return min
    }

}

fun main() {
    println(TSPKT().g(0, arrayListOf(1, 2, 3)))
}
