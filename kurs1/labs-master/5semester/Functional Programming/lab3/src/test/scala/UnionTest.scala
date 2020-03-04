import org.scalatest.{FlatSpec, Matchers}

class UnionTest extends FlatSpec with Matchers {

  import Lab3.union

  "union(Set(1, 2), Set(3, 4))" should "Set(1, 2, 3, 4)" in { union(Set(1, 2), Set(3, 4)) shouldBe Set(1, 2, 3, 4) }
  "union(Set(1, 2), Set(2, 3))" should "Set(1, 2, 3)" in { union(Set(1, 2), Set(2, 3)) shouldBe Set(1, 2, 3) }

}
