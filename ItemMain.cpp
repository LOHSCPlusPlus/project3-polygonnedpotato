#include <stdlib.h>
#include "ItemDB.h"
#include "ReadUtils.h"
using namespace std;

int main() {
  birdB db;
  cout<<"\n\tBIRDS DB\n";
  bool loop=1;
  while(loop){
    int s=readInt("ENTER OPTION:\n0)\tRESET DB\n1)\tPRINT DB\n4)\tPRINT ENDANGERED\n5)\tEXIT\n ");
    switch(s){
      case 0:
        db.ftm();
        break;
      case 1:
        db.print();
        break;
      case 2:
        db.yesBird();
        break;
      case 3:
        db.noBird();
        break;
      case 4:
        db.printEnd();
        break;
      case 5:
        loop=0;
        break;
      default:
        clog<<"\n🤨📸";
    }
  }
  clog<<getenv("segment");
  return 0;
}
