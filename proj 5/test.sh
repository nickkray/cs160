#make clean 
 echo "==================== compiling compiler =====================" 
 make 
 echo "=================== compiling test ====================="
 ./csimple < test
 ./csimple < test > testme.s 
 echo "==================== assembling ====================" 
 gcc -c -m32 -o testme.o testme.s 
 gcc -c -m32 -o start.o start.c 
 gcc -m32 -o start start.o testme.o 
 echo "==================== running ==================== " 
  ./start
