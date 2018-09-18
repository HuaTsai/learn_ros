namespace lib_test {
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
    * \param width   rectangle width
    */
    Rectangle(int length, int width);
    /** \brief compute the area
     * 
     * by use length multiply width
     */
    int area();
    /** \brief print the computed area */
    void print();
   private:
    int length_;  /**< length */
    int width_;  /**< width */
  };
}