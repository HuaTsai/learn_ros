/** \author HuaTsai */

namespace lib_test {
  //* A rectangle class
  /**
  * The basic rectangle class, it does:
  * 1. calculate area
  * 2. print above area
  */
  class Rectangle {
   public:
    /** \brief default constructor */    
    Rectangle();
    /** \brief length and width constructor
    * \param length   rectangle length
    * \param length   rectangle width
    */
    Rectangle(int length, int width);
    /** \brief compute the area */
    int area();
    /** \brief print the computed area */
    void print();
   private:
    int length_;  /**< length */
    int width_;  /**< width */
  };
}