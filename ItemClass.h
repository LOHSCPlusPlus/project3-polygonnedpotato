#include <iostream>
class Bird{
  public:
    Bird();
    void lf(std::ifstream &in);
    void lin();
    void print();
    char* getCstat();
    bool getGood();
  private:
    char name[100];
    char sciName[100];
    char cstat[100];
    char primaryColor[100];
    char diet[100];
    bool good;
};