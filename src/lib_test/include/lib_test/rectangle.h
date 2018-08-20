namespace lib_test {
  class Rectangle {
   public:
    Rectangle();
    Rectangle(int length, int width);
    int area();
    void print();
   private:
    int length_;
    int width_;
  };
}