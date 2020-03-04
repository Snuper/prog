object Lab1 extends App {

  println("lab 1:")
  println("1.")

  def getAtom(a:(Int, (Int, (Int, Int), Int), Int)) :Int = {
    a._2._2._1
  }

  val atom_in: Int = 23//readInt()
  val atom = getAtom((1, (2, (atom_in, 3), 4), 5))
  println("atom: " + atom)


  println("\n3.")

  def twoToThree[T](list:List[T]) :List[T] = {
    if(list.size < 3) list
    else list(0)::list(2)::list(1)::list.drop(3)
  }

  println("Функция twoToThree меняет 2 и 3 элемент в списке " + twoToThree(1::2::3::4::Nil))
}
