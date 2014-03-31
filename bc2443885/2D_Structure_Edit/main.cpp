/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 23, 2013, 8:22 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Our Libraries
#include "Array.h"
#include "Array2d.h"

//Global Constants
const int ROW = 10;

//Function Prototypes
Array *filStrct(int);
void   prntStrc(Array *,int);
void   dstrStr(Array *);
//Create and implement
Array2d *filStrc2(int,int);
void   prntStrc(Array2d *,int);
void   dstrStr(Array2d *);

int main(int argc, char** argv) {
    //Initialize random number seed
    srand(static_cast<unsigned int>(time(0)));
    
  //1D Arrays
    cout<<"1D Array:  "<<endl;
    //Allocate the array structure
    Array *array1=filStrct(100);
    //Print the structure
    prntStrc(array1,10);
    //Deallocate memory
    dstrStr(array1);
    
  //2D Arrays
    cout<<"2D Array:  "<<endl;
    Array2d *d2Arr = filStrc2(10,10);
    prntStrc(d2Arr,10);
    //Deallocate memory
    dstrStr(d2Arr);
    
    //Exit stage right
    return 0;
}

//1D functions
void   dstrStr(Array *a){
    //Deallocate the data first
    delete [] a->data;
    //Deallocate the array structure
    delete a;
}
void   prntStrc(Array *a,int colPRow){
    //Output the array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%colPRow==(colPRow-1))
            cout<<endl;
    }
    cout<<endl;
}
Array *filStrct(int n){
    //Create the pointer to a structure
    Array *a=new Array;
    //Set the size of the array in the structure
    a->size=n;
    //Allocate the array
    a->data=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;
    }
    //Return the structure
    return a;
}

//2D functions
Array2d *filStrc2(int c,int r){    
  //Create pointer
    Array2d *a = new Array2d;
  //Set sizes
    a->col = c;
    a->row = r;
  //Allocate
    int **temp = new int *[c];
    for(int i=0;i<c;i++){
        temp[i] = new int [r];
    }
  //Fill
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp[i][j]=rand()%90+10;
  //Return structure
    a->data = temp;
    return a;
}
void   prntStrc(Array2d *a,int l){
    cout<<endl;
    for(int i=0;i<a->row;i++){
        for(int j=0;j<a->col;j++){
            cout<<a->data[i][j]<<" ";
            if(j%l==(l-1))
                cout<<endl;
        }
    }
}
void   dstrStr(Array2d *a){
    //Deallocate the data first
    delete [] a->data;
    //Deallocate the array structure
    delete a;
}