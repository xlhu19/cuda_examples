import java.io._

class Point(xc: Int, yc: Int) {
   var x: Int = xc
   var y: Int = yc

   def move(dx: Int, dy: Int) {
      x = x + dx
      y = y + dy
      println ("x is: " + x);
      println ("y is: " + y);
   }
}

object Test {
   def main(args: Array[String]) {
      val pt = new Point(10, 20);
      pt.move(10, 10);
   }
}
