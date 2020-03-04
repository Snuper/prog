package ruban

import scala.collection.mutable

//Рюкзак
object lab6 extends App {
  case class Product(weight: Int, cost: Int)

  class RecureCache[A, B](f: (A, RecureCache[A, B]) => B){
    private val map = mutable.HashMap.empty[A, B]
    def apply(a: A): B = map.get(a) match {
      case Some(value) => value
      case None =>
        val res = f(a, this)
        map(a) = res
        res
    }
  }

  object RecureCache {
    def apply[A, B](f: (A, RecureCache[A, B]) => B): RecureCache[A, B] = new RecureCache(f)
  }

  def f(products: Seq[Product], M: Int): Option[Int] = {
    def recF(M: Int, cache: RecureCache[Int, Option[Int]]): Option[Int] = if (M < 0) None else {
      Some(max(products.map {
        product => cache(M - product.weight).map(_ + product.cost)
      }))
    }
    RecureCache(recF)(M)
  }

  def max(seq: Seq[Option[Int]]): Int = seq.flatten.reduceOption(_ max _).getOrElse(0)

  println(f(Seq(Product(3, 8), Product(5, 14), Product(8, 23)), 100))
}
