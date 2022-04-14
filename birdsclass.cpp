#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int M=100;
const int L=512;
const char N='\0';
// const char E[M]={'E','n','d','a','n','g','e','r','e','d','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
int exite(){
  char message[]={73,116,32,115,116,105,114,115,46,32,73,116,32,98,114,101,97,116,104,101,115,32,97,32,115,108,111,119,32,112,97,116,116,101,114,110,32,111,102,32,105,110,104,97,108,101,115,32,97,110,100,32,101,120,104,97,108,101,115,44,32,119,104,105,108,115,116,32,119,97,116,99,104,105,110,103,32,111,118,101,114,32,97,108,108,32,102,111,114,109,115,32,111,102,32,108,105,102,101,46,32,73,116,32,112,111,110,100,101,114,115,32,97,98,111,117,116,32,111,110,101,32,116,104,105,110,103,32,105,110,32,112,97,114,116,105,99,117,108,97,114,58,32,72,117,109,97,110,105,116,121,46,32,87,105,116,104,32,99,117,114,105,111,115,105,116,121,44,32,73,116,32,115,116,117,100,105,101,115,32,116,104,101,32,108,105,118,101,115,32,111,102,32,116,104,101,32,104,117,109,97,110,115,44,32,104,111,112,105,110,103,32,116,111,32,108,101,97,114,110,32,119,104,97,116,32,105,116,32,105,115,32,108,105,107,101,32,116,111,32,98,101,32,111,110,101,46,32,73,116,32,99,104,111,111,115,101,115,32,116,111,32,119,97,116,99,104,32,102,114,111,109,32,97,32,102,97,114,32,100,105,115,116,97,110,99,101,44,32,97,115,32,116,111,32,104,111,112,101,102,117,108,108,121,32,112,114,101,118,101,110,116,32,97,32,114,101,112,101,97,116,32,111,102,32,105,116,39,115,32,108,97,115,116,32,109,105,115,116,97,107,101,46,46,46,10,10,65,32,109,105,115,116,97,107,101,32,116,104,97,116,32,97,108,109,111,115,116,32,119,105,112,101,100,32,111,117,116,32,97,108,108,32,108,105,102,101,32,105,110,32,116,104,101,32,107,110,111,119,110,32,117,110,105,118,101,114,115,101,46,46,46,'\0'};
  // thing i wrote^^ (no capitalisation errors)
  cout<<message<<endl;
  return 0;
}
struct bird{
  char name[M];
  char sciName[M];
  // enum constatus{EX,EW,CR,EN,VU,NT,CD,LC,DM,DD,NE} cstat; //Based off actual labels (https://en.wikipedia.org/wiki/Conservation_status)
  char cstat[M];
  char primaryColor[M];
  char diet[M];
  bird();
};
bird::bird(){
  for(int c;c<M;c++){
    name[c]='\0';
    sciName[c]='\0';
    cstat[c]='\0';
    primaryColor[c]='\0';
    diet[c]='\0';
  };
  // cstat=NE;
};
bird fl(ifstream &in){
  bird t;
  in.get(t.name,M,';');
  in.ignore(M,';');
  in.get(t.sciName,M,';');
  in.ignore(M,';');
  in.get(t.cstat,M,';');
  cout<<t.cstat;
  in.ignore(M,';');
  in.get(t.primaryColor,M,';');
  in.ignore(M,';');
  in.get(t.diet,M,'\n');
  // in.ignore(M,'\n');
  return t;
}
int resetDB(bird (&all)[L]){
  clog<<"loading db...";
  try{
    int index=0;
    ifstream inf("./birds.txt");
    while(inf.peek()!=EOF&&index<L){
      all[index]=fl(inf);
      index++;
    }
    clog<<"\e[1;32mDONE! ("<<index<<" entries)\e[0m\n";
    return index;
  }catch(...){
    cerr<<"\e[1;31mFAILED!\nACCESS DENIED OR FILE DOES NOT EXIST!\n\e[0m;";
    return 0;
  }
}
void printDB(bird all[L],int index){
  for(int x=0;x<index;x++){
    cout<<all[x].name<<'|'
        <<all[x].sciName<<'|'
        <<all[x].cstat<<'|'
        <<all[x].primaryColor<<'|'
        <<all[x].diet<<endl;
  }
}
void add(bird (&all)[L],int &index){
  string input;
  bird wr;
  cout<<"NAME:";
  cin>>input;
  strcpy(wr.name,input.c_str());
  cout<<"SCINAME:";
  cin>>input;
  strcpy(wr.sciName,input.c_str());
  cout<<"CSTAT:";
  cin>>input;
  strcpy(wr.cstat,input.c_str());
  cout<<"PRIMARYCOLOR:";
  cin>>input;
  strcpy(wr.primaryColor,input.c_str());
  cout<<"DIET:";
  cin>>input;
  strcpy(wr.diet,input.c_str());
  all[index]=wr;
  index++;
  cout<<"DONE!";
}
void remove(bird (&all)[L],int &index){
  cout<<"INDEX TO REMOVE:";
  int entry;
  cin>>entry;
  if(entry<0||entry>=index){
    cerr<<"OUT OF BOUNDS!";
    throw(1);
  }
  for(int c=entry;c!=index;c++){
    all[c]=all[c+1];
  }
  index--;
  cout<<"DONE!\n";
}

void printsp(bird all[L],int i){
  for(int c=0;c<i;c++){
    if((string)all[c].cstat=="Endangered"){
      cout<<all[c].name<<','
          <<all[c].sciName<<','
          <<all[c].cstat<<','
          <<all[c].primaryColor<<','
          <<all[c].diet<<endl;
    }
  }
}
void commit(bird all[L],int m){
  ofstream out;
  out.open("birds.txt");
  int in;
  cout<<"COMMIT DATABASE?(1 for yes, 0 for no)\t";
  cin>>in;
  if(in){
    for(int x=0;x<m;x++){
      out<<all[x].name<<';'
        <<all[x].sciName<<';'
        <<all[x].cstat<<';'
        <<all[x].primaryColor<<';'
        <<all[x].diet<<endl;
    }
    cout<<"done";
  }
}
int main(){
  bird all[L];
  int e=resetDB(all);
  bool k=1;
  int sel;
  while(k){
    cout<<"\n\nBIRD DB\n\t"<<e<<" ENTRIES IN MEMORY\n0)\tRELOAD DB\n1)\tPRINT DB\n2)\tADD ENTRY\n3)\tREMOVE ENTRY\n4)\tPRINT ENDANGERED\n5)\tCOMMIT DB\n6)\tEXIT\nOPTION:";
    cin>>sel;
    switch(sel){
      case 0:
        e=resetDB(all);
        break;
      case 1:
        printDB(all,e);
        break;
      case 2:
        add(all,e);
        break;
      case 3:
        remove(all,e);
        break;
      case 4:
        printsp(all,e);
        break;
      case 5:
        commit(all,e);
        break;
      case 6:
        k=exite();
        break;
      default:
        cerr<<"WTF?!";
        exit(1);
    }
  }
  return 0;
}