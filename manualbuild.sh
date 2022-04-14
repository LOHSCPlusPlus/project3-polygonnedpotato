# in case make doesn't do shit
rm -rf ./*.o ./ItemDB
g++ -Wall -c ReadUtils.cpp  -o ReadUtils.o
g++ -Wall -c ItemClass.cpp  -o ItemClass.o
g++ -Wall -c ItemDB.cpp  -o ItemDB.o
g++ -Wall -c ItemMain.cpp  -o ItemMain.o
g++ ItemDB.o ItemClass.o ReadUtils.o ItemMain.o -o ItemDB