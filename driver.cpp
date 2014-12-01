/*
Author : Michael Rijlaarsdam
Lab #7 Memory Management
Purpose : This is the driver for testing a program that simulates memory management with a class
Can only handle ints;
Functions will be in a seperate linked file
*/
#include "memory.h"

int main () {
/*
    memory mem1 = memory(60);
    memory mem2 = memory(mem1);

    mem1.storeInt(55,25);
    mem1.storeInt(45,25);
    mem1.storeInt(1,1);
    mem1.storeInt(2,2);
    mem1.storeInt(3,3);

    mem1[65]=4;

    mem1.blockCopy(1,5,3);

    mem1.dump(1,3);
    mem2.dump();
    mem2=mem1+mem1;
    mem1.dump();
    mem2.dump();
    if (mem1+mem1==mem2)cout<<"hippopotamus"<<endl;*/
memory A(100);  // memory with 100 locations using constructor

                 
  memory B;    
  for (int i =0; i<50; i++)
     B[i] = 5;          // set first 50 locations to 5

  A = B;                    
  if ( A == B ) cout << " A is equal to B"<<endl;
      else cout << " A is not equal to B"<<endl;

  A[1] = 3;
  if ( A == B ) cout << " A is equal to B"<<endl;
      else cout << " A is not equal to B"<<endl;


cout << A;     /* this dumps all of A */
A.dump();       /* this also dumps all of A */

memory C = A;  
C = C + A;     /* addition*/
cout << C;     /* dumps C, or you can use C.dump() until you are ready to write this */


    return 0;
}
