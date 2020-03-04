import org.scalatest._

class BelongsTest extends FlatSpec with Matchers {

  import Lab3.BelongsSet

  "Set(1, 2) belongs Set(1, 2, 4)" should "true" in { Set(1, 2) belongs Set(1, 2, 4) shouldBe true }
  "Set(1, 2, 3) belongs Set(1, 2, 4)" should "false" in { Set(1, 2, 3) belongs Set(1, 2, 4) shouldBe false }

}
