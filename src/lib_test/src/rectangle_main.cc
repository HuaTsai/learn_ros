#include <lib_test/rectangle.h>

int main() {
  lib_test::Rectangle rec(3, 4);
  rec.print();
  rec = lib_test::Rectangle(5, 6);
  rec.print();
}