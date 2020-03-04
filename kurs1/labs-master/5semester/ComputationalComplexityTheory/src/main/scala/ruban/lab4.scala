package ruban

object lab4 extends App {
  val x = Seq(9, 9)
  val y = Seq(9, 9, 9)

  def mult(x: Seq[Int], y: Seq[Int]): Seq[Int] = {
    val result = Array.ofDim[Int](x.length + y.length).map(_ => 0)
    val (reverseX, reverseY) = (x.reverse, y.reverse)
    reverseX.indices.foreach{
      i => reverseY.indices.foreach{
        j => {
          val numb = reverseX(i) * reverseY(j) + result(i + j)
          result(i + j) = numb % 10
          result(i + j + 1) += numb / 10
        }
      }
    }
    result.reverse
  }

  println(mult(x, y))
}
