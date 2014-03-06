/* 
 * File:   main.cpp
 * Author: Oscar Martinez 
 *
 * Created on March 3, 2014, 1:11 PM
 */

//Libraries 
#include <cstdlib>
#include <iostream>
//#include <ctime>

using namespace std;

//Global constants 

//Function Prototypes 
int * fillAry(int); 
void prntAry(int *, int, int); 
void sort(int *, int *, int); 
int maxFreq(int *, int); 
int nuModes(int *, int, int );
void destroy(int *); 

int main(int argc, char** argv) {

    const int SIZE =105; 
    int brray[SIZE]; 
    //Fill the array wiht 0-9
    int * array=fillAry(SIZE); 
    //print the array 
    prntAry(array, SIZE, 10); 
    //sort the copies array 
    sort(array,brray,SIZE); 
    //Print the sorted array
    prntAry(brray,SIZE,10); 
    //What is the max frequency
    cout<< "The max frequency in the array = "<<maxFreq(brray, SIZE);
    //Exit stage right 
    destroy(array); 
    return 0;
}
//repetitive count with one digit elements 
int * fillAry(int n){ 
    //Allocate memory
    int *a=new int[n]; 
    //Fill the array
    for(int i=0; i< n; i++){ 
        a[i]= i%10; 
    }
    return a; 
}

void prntAry(int *a, int n, int perline){ 
    cout <<endl; 
    for(int i=0; i< n; i++){ 
        cout <<a[i] <<" "; 
        if(i%perline ==(perline-1))cout<<endl;
    }
    cout<<endl; 
}

void sort(int *a, int *b, int n) {
    //Make a copy 
    for(int i=0; i< n; i++){ 
        b[i]=a[i]; 
    } 
    //Sort the copied array 
    for(int i=0; i<n; i++){ 
        for(int j=i+1; j<n; j++){ 
            if(b[i]>b[j]){ 
                int temp=b[i]; 
                b[i]=b[j]; 
                b[j]=temp;
            }
        }
    }
}

//Requires sorted array for an input
int maxFreq(int *a, int n){ 
    //Declare counters 
    int count=1, max=1; 
    //Loop and compare
    for(int i=1;i<n; i++){ 
        if(a[i-1]==a[i]){ 
            count++; 
            if(count>max)max=count; 
        }else{ 
            count =1; 
        }
    }
    return max; 
}

void destroy(int *a){ 
    delete [] a; 
}