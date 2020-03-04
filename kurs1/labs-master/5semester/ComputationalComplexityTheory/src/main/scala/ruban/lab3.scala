package ruban

object lab3 extends App{
  trait Sum[T]{
    def apply(t1: T, t2: T): T
  }

  def convolution[T : Sum](a: Seq[T], b: Seq[T]): Seq[T] ={
    a.flatMap(
      aElem => b.map(
        bElem => implicitly[Sum[T]].apply(aElem, bElem)
      )
    )
  }

  implicit val intSum: Sum[Int] = (t1: Int, t2: Int) => t1 + t2

  println(convolution(Seq(1, 2, 3), Seq(3, 4, 5)))
}
