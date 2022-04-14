#include "ItemClass.h"
class birdB{
  public:
    void ftm();
    birdB();
    void print();
    void printEnd();
    void yesBird();
    void noBird();
  private:
    enum{LIMIT=4096};
    // enum{LIMIT=8192}; //for mem limit test
    int size;
    Bird arr[LIMIT];
};