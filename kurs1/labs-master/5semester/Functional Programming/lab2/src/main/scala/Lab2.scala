object Lab2 extends App {

  println("Lab2")
  println("4.")

//  4) Добавляющую заданное параметром x число к каждому числовому элементу списка.
//  Например, x=3, L=(a -1 6 v 3) –> (a 2 9 v 6).

  def task4(list: List[AnyVal], x: Int) :List[AnyVal] = list match {
    case Nil => Nil
    case head::tail => head match {
      case head: Int => (head + x)::task4(tail, x)
      case _ => head::task4(tail, x)
    }
  }

  val list4 = List[AnyVal]('a', -1, 6, 'v', 3)
  val x4 = 3

  println(s"x=$x4, (${list4.mkString(" ")}) -> (${task4(list4, x4).mkString(" ")})")


  println("\n14.")

//  14) Преобразующую список в множество.
//  Например, (a b a a c c) –> (a b c).


  def toSet[T](list: List[T]): List[T] = list match {
    case Nil => Nil
    case head::tail => head::toSet(delElem(tail, head))
  }

  def delElem[T](list: List[T], elem: T): List[T] = list match {
    case Nil => Nil
    case head::tail => if(head == elem) delElem(tail, elem) else head::delElem(tail, elem)
  }

  val list14 = List('a', 'b', 'a', 'a', 'c', 'c')

  println(s"(${list14.mkString(" ")}) -> (${toSet(list14).mkString(" ")})")


  println("\n24.")

//  24) Переставляющую элементы списка таким образом, чтобы одинаковые элементы
//  оказались рядом. Сортировку не использовать!
//    Например, (1 5 2 1 4 3 1 2 4 5 4) –> (1 1 1 5 5 2 2 4 4 4 3)

  def task24(list: List[Int]): List[Int] = list match {
    case Nil => Nil
    case list => {
      val (all_numb_list, main_list) = getAllNumb(list, list.head)
      all_numb_list:::task24(main_list)
    }
  }

  def getAllNumb(list: List[Int], numb: Int): (List[Int], List[Int]) = list match {
    case Nil => (Nil, Nil)
    case head::tail => if(head == numb) {
      val (numb_from_list, main_list) = getAllNumb(tail, numb)
      (head::numb_from_list, main_list)
    } else {
      val (numb_from_list, main_list) = getAllNumb(tail, numb)
      (numb_from_list, head::main_list)
    }
  }

  val list24 = List(1, 5, 2, 1, 4, 3, 1, 2, 4, 5, 4)

  println(s"(${list24.mkString(" ")}) -> (${task24(list24).mkString(" ")})")
}
