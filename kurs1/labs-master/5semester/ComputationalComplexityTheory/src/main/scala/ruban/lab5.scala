package ruban

import scala.annotation.tailrec

object lab5 extends App {
  def fordBel(matrix: Seq[Seq[Option[Int]]], v0: Int): Seq[Option[Int]] = {
    require(v0 < matrix.length)
    require(matrix.length == matrix.minBy(_.length).length)
    @tailrec def recureFordBell(D: Seq[Option[Int]]): Seq[Option[Int]] = {
      val DplusOne = D.indices.map {
        i =>
          min(D.indices.map {
            j =>
              for {
                d <- D(j)
                c <- matrix(i)(j)
              } yield c + d
          })
      }
      if(D == DplusOne) DplusOne else recureFordBell(DplusOne)
    }

    def min(seq: Seq[Option[Int]]): Option[Int] = seq.flatten.reduceOption(_ min _)
    recureFordBell(matrix(v0))
  }

  val C = Seq(
    Seq(Some(0), Some(25), Some(15), Some(7), Some(2)),
    Seq(Some(25), Some(0), Some(6) , None, None),
    Seq(Some(15), Some(6), Some(0), Some(4), None),
    Seq(Some(7) , None, Some(4), Some(0), Some(3)),
    Seq(Some(2), None, None, Some(3), Some(0))
  )

  println(fordBel(C, 0))
}
