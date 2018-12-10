import java.util.Scanner
import kotlin.math.min

lateinit var dp: Array<IntArray>
var K: Int = 0
lateinit var sums: IntArray
lateinit var items: Array<Int>

fun main() {
  val scanner = Scanner(System.`in`)
  var T = scanner.nextInt()

  while(T > 0) {
    K = scanner.nextInt()
    scanner.nextLine()
    dp = Array<IntArray>(K) {
      IntArray(K) { -1 }
    }
    sums = IntArray(K) { 0 }
    items = scanner.nextLine()
        .split(" ")
        .map { it.toInt() }
        .toTypedArray()
    items.forEachIndexed { idx, item ->
      if (idx == 0) {
        sums[idx] = item
        return@forEachIndexed
      }
      sums[idx] = sums[idx - 1] + item
    }
    println("dp: ${dp[2][2]}")
    println(solve(0, items.size - 1))
    T -= 1
  }
}

fun solve(i: Int, j: Int): Int {
  if (i > j) {
    return 0
  }
  if (i == j) {
    return items[i]
  }
  if (dp[i][j] != -1) {
    return dp[i][j]
  }
  var result = Int.MAX_VALUE
  for (k in i until j) {
    var left = solve(i, k)
    if (k - i >= 1) {
      left += sums[k] - (sums.getOrNull(i - 1) ?: 0)
    }
    var right = solve(k + 1 , j)
    if (j - (k+1) >= 1) {
      right += sums[j] - (sums.getOrNull(k) ?: 0)
    }
    result = min(result, left + right)
  }
  println("$i ~ $j: $result")
  return result.apply { dp[i][j] = this }
}