#include "ItemDB.h"
#include "ItemClass.h"
#include "ReadUtils.h"
#include <fstream>
#include <string>
using namespace std;
void birdB::ftm(){
  clog<<"COPYING DATABASE FROM FILE TO MEMORY.";
  // ifstream inpu("birds.txtdb",ifstream::in);
  ifstream inpu;
  inpu.open("birds.txtdb");
  clog<<".";
  size=0;
  clog<<".";
  while(inpu.good()&&size<LIMIT){
    arr[size].lf(inpu);
    size++;
    clog<<".";
  }
  clog<<"DONE\nLOADED IN "<<size<<" BIRDS(S)!";
  inpu.close();
}
birdB::birdB(){
  ftm();
}
void birdB::print(){
  for(int x=0;x<size;x++){
    arr[x].print();
  }
}
void birdB::printEnd(){
  for(int c=0;c<size;c++){
    if((string)arr[c].getCstat()=="Endangered"){
      arr[c].print();
    }
  }
}
void birdB::yesBird(){
  int c;
  for(c=0;c<size&&c<LIMIT;c++){
    if(!arr[c].getGood()){
      break;
    }
  }
  arr[c].lin();
  clog<<"Done!";
}
void birdB::noBird(){
  bool keep=1;
  while(keep){
    int index=readInt("ENTER INDEX");
    if(index>=size||index<0||index>=LIMIT){
      clog<<"🙁\n"; // https://www.youtube.com/watch?v=KbksFFpniuc
    }else{
      Bird em;
      arr[index]=em;
      keep=0;
    }
  }
}