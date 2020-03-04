
object Lab3 {

  implicit class BelongsSet[T](subset: Set[T]) {
    def belongs(set: Set[T]): Boolean = subset.forall((elem: T) => set(elem))
  }

  def union[T](set1: Set[T], set2: Set[T]): Set[T] = set2.foldRight(set1)(
    (elemSet2, set) => set + elemSet2
  )

  implicit class MyMapSet[T >: Char](set: Set[T]) {
    def myMap(func: T => Boolean): Set[T] = set.map(elem => if(func(elem)) elem else '*')
  }

}
