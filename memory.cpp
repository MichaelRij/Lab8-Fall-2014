/*
Author : Michael Rijlaarsdam
Lab #7 Memory Management
Purpose : This is the functions for a program that simulates memory management with a class
Can only handle ints;
Functions will be in a seperate linked file
*/

#include "memory.h"

    

    memory::memory(int length){//construct memory space of specified length in words
		mem.resize(length);
	
    }

    memory::memory(const memory &m){   //construct memory space of default length
		int size=((memory &)m).getCap();
		mem.resize(size);
		for(int i =0;i<size;i++){
			mem[i]=m.mem[i];
		}
    }

    int memory::storeInt(int loc,int val){//place first int in location of second 
				  	  //returns a negative if theres an error
		if(loc<0) return -1;
		if(loc>=mem.capacity()){
	    	mem.resize(loc+10);
		}
		mem[loc] = val;
		return 0;
    }

    int memory::getInt(int loc) const{//takes the value from a given memory location returns a 
				//negative if theres an error
		if(loc<0)return -1;
		if(loc>mem.capacity())return -1;
		return mem[loc];
	
    }

    int memory::blockCopy(int source,int dest,int length){//start memory location, dest memory loc, length

		if(dest+length>mem.capacity())return -1;

		vector<int> tmp(length);

		for(int i = 0; i<length; i++){//copy to a small array
			tmp[i]=mem[i+source];
		}
		for(int i = 0; i<length; i++){//copy to the old array
			mem[i+dest]=tmp[i];
		}

	return 0;
    }

    void memory::dump(int startLoc,int endLoc) const{// dumps specified start location to end location
	
		int numCol = 10;//set up 0-9 index
	
		printf("      ");
		for(int s=0; s<numCol; s++)
			printf("%6d", s);
		printf("\n");

		for (int i = (startLoc/numCol)*numCol; i<endLoc; i+=numCol){//integer division to drop to 										//nearest 10
			printf("%5d: ", i);
				for(int a=i; a<numCol+i; a++){
				printf("%05d ",mem[a]);
			}
			printf("\n");
		}
    }

    void memory::dump() const{// dumps all 
		dump(0,mem.capacity());
	
    }
///////////////////////////////////////////////////////////////////////////////////////////
    int& memory::operator[](int loc){// allows the user to a memory cell

	return mem[loc];
    }

    const int memory::operator[](int a)const{// allows the user to get a memory cell
	return getInt(a);
    }

    memory memory::operator+(memory m){// adds this memory to another in a new one and returns that third one

	int num=mem.capacity();
		memory r = memory(num);

		for (int i=0;i<mem.capacity();i++){
			r[i]=mem[i]+m[i];
		}
	return r;
    }

    bool memory::operator==(memory m){// returns true only if every cell of memory is the same
		for(int i=0;i<mem.capacity();i++){
			if(mem[i]!=m[i])return false;
		}
	return true;
    }

    void memory::operator=(memory m){//copies every cell into this memory
		int num=mem.capacity();
		for(int i=0;i<num;i++){
			mem[i]=m[i];
		}
    }

    ostream& operator<<(ostream &s, const memory &m){// dumps all cells
		m.dump();//(memory & (m))
	return s;
    }
    

