#include <cstring>
#include <bits/stdc++.h>
#include "ItemClass.h"
#include "ReadUtils.h"
const int M=100;
const char N='\0';
Bird::Bird(){
  for(int c;c<M;c++){
    name[c]=N;
    sciName[c]=N;
    cstat[c]=N;
    primaryColor[c]=N;
    diet[c]=N;
  };
  good=0;
}
void Bird::lf(std::ifstream &in){
  in.get(name,M,';');
  in.ignore(M,';');
  in.get(sciName,M,';');
  in.ignore(M,';');
  in.get(cstat,M,';');
  // cout<<cstat;
  in.ignore(M,';');
  in.get(primaryColor,M,';');
  in.ignore(M,';');
  in.get(diet,M,'\n');
  // in.ignore(M,'\n');
  good=1;
}
void Bird::lin(){
  std::cout<<"NAME:";
  std::cin>>name;
  std::cout<<"SCINAME:";
  std::cin>>sciName;
  std::cout<<"CSTAT:";
  std::cin>>cstat;
  std::cout<<"PRIMARYCOLOR";
  std::cin>>primaryColor;
  std::cout<<"DIET:";
  std::cin>>diet;
  good=1;
}
void Bird::print(){
  std::cout<<name<<'|'
           <<sciName<<'|'
           <<cstat<<'|'
           <<primaryColor<<'|'
           <<diet<<std::endl;
}
char* Bird::getCstat(){return cstat;}
bool Bird::getGood(){return good;}