
/*
Author : Michael Rijlaarsdam
Lab #8 Memory Management operators
Purpose : This is the header for a program that simulates memory management with a class
Can only handle ints;
Functions will be in a seperate linked file
Has operators
*/
#ifndef MEMORY
#define MEMORY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class memory{
private:
    vector<int> mem;

public:
    memory(int length=100);//construct memory space of specified length
    memory(const memory &);//construct memory as a deep copy of another memory

    int getCap(){return mem.capacity();}//returns the max size
    int storeInt(int,int);//place first int in location of second; returns a negative if theres an error
    int getInt(int) const;//takes the value from a given memory location returns a negative if theres an error
    int blockCopy(int,int,int);//source memory location, dest memory location, length
    void dump (int,int) const;// dumps specified start location to end location
    void dump() const;// dumps all 
    int& operator[](int);// allows the user to a memory cell
    const int operator[](int)const;// allows the user to get a memory cell
    memory operator+(memory);// adds another memory to this one individually
    bool operator==(memory);// returns true only if every cell of memory is the same
    void operator=(memory);//copies every cell into this memory
    
    
    
};
ostream& operator<<(ostream &, const memory &);// dumps all cells

#endif

