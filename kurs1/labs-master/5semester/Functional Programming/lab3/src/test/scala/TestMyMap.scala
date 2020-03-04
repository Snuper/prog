import org.scalatest.{FlatSpec, Matchers}

class TestMyMap extends FlatSpec with Matchers {

  import Lab3.MyMapSet

  """Set('a', 'b', 'c', 'd').myMap( x => x < 'c' )""" should """Set('a', 'b', '*', '*')""" in {
    Set('a', 'b', 'c', 'd').myMap( _ < 'c' ) shouldBe Set('a', 'b', '*', '*')
  }

  "Set(2.4, 'a', 'r', 0).myMap( x is char )" should "Set('*', 'a', 'r', 0)" in {
    Set[AnyVal](2.4, 'a', 'r', 0).myMap {
      case _: Char => true
      case _ => false
    } shouldBe Set('*', 'a', 'r', '*')
  }

  "Set(1, 2, -4, 0).myMap( (x) => x >= 0 )" should "Set(1, 2, '*', 0)" in {
    Set[AnyVal](1, 2, -4, 0).myMap {
      case x: Int => x >= 0
      case _ => true
    } shouldBe Set(1, 2, '*', 0)
  }

}
