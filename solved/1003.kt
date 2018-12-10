import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
  val zeroCnt = IntArray(41)
  val oneCnt = IntArray(41)
  zeroCnt[0] = 1
  oneCnt[1] = 1
  for (idx in 2 until 41) {
    zeroCnt[idx] = zeroCnt[idx -1] + zeroCnt[idx - 2]
    oneCnt[idx] = oneCnt[idx -1] + oneCnt[idx - 2]
  }

  val reader = BufferedReader(InputStreamReader(System.`in`))

  repeat(reader.readLine()!!.toInt()) {
    val target = reader.readLine()!!.toInt()
    println("${zeroCnt.get(target)} ${oneCnt.get(target)}")
  }
}