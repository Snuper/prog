package ruban

import math.Ordering

object lab1 extends App {

  val array = Array(2, 7, 5, 4, 9, 12, 15, 5)

  println("test bubble sort " + (bubbleSort(array)._1 sameElements array.sorted))
  val (selectSortArray, complexity) = selectSort(array)
  println("test select sort " + (selectSortArray sameElements array.sorted))
//  println("real complexity = " + complexity.complexity + ",  theory complexity = " + (array.length * (array.length + 1))/2)
  println("array: " + array.mkString(" "))

  def bubbleSort[T: Ordering](array: Array[T]): (Array[T], ComplexitySort) = {
    var comp: Int = 0
    var perm: Int = 0

    val buff = array.clone

    buff.indices.foreach{
      i => (buff.length - 1).until(i, -1).foreach{
        j => {
          comp += 1
          if(implicitly[Ordering[T]].lt(buff(j), buff(j - 1))) {
            swap(buff, j, j - 1)
            perm+=3
          }
        }
      }
    }

    (buff, ComplexitySort(comp, perm))
  }

  def selectSort[T: Ordering](array: Array[T]): (Array[T], ComplexitySort) = {
    var comp = 0
    var perm = 0

    val buff = array.clone
    buff.indices.foreach{
      i => {
        var indexMinElem = i
        (i + 1 until buff.length).foreach{
          comp += 1
          j => if(implicitly[Ordering[T]].lt(buff(j), buff(indexMinElem))) {
            indexMinElem = j
          }
        }
        perm+=3
        swap(buff, i, indexMinElem)
      }
    }

    (buff, ComplexitySort(comp, perm))
  }

//  def mergeSort[T: Ordering](array: Array[T]): (Array[T], ComplexitySort) = {
//    var comp = 0
//    var perm = 0
//
//    val buff = array.clone
//
//    def recursiveMergeSort(array: Array[T]): Array[T] = array match {
//      case Array(_) => array
//      case _ =>
//        val (left, right) = array.splitAt(array.length / 2)
//        recursiveMergeSort(left)
//        recursiveMergeSort(right)
//    }
//
//    (buff, ComplexitySort(comp, perm))
//  }

  def swap[T](array: Array[T], a: Int, b: Int): Unit = {
    val buffer = array(a)
    array(a) = array(b)
    array(b) = buffer
  }
}

trait Complexity {
  def complexity: Int
}

case class ComplexitySort(comp: Int, perm: Int) extends Complexity {
  val complexity: Int = comp + perm
}