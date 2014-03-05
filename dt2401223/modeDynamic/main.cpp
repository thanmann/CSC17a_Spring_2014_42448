/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 3, 2014, 1:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
int * fillAry(int);
void prntAry(int *,int,int);
void sort(int *,int [],int);
int maxFreq(int *,int);
int nuModes(int *,int,int);
void destroy(int *);

int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=105;
    int brray[SIZE];
    //Fill the Array with 0-9
    int *array=fillAry(SIZE);
    //print the array
    prntAry(array,SIZE,10);
    //Sort copied array
    sort(array,brray,SIZE);
    //Print sorted array
    prntAry(brray,SIZE,10);
    //What is the max frequency
    cout<<"THe max freq in the array = "<<maxFreq(brray,SIZE)<<endl;
    destroy(array);
    return 0;
}
void destroy(int *a){
    delete [] a;
}

//Requires sorted array for input
int maxFreq(int *a,int n){
    //Declare counter
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }
        else{
            count=1;
        }
    }
    return max;
}

void sort(int *a,int b[],int n){
    //Make a copy
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Sort copied array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}



void prntAry(int *a,int n,int perline){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    //Allocate Memory
    int *a=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
    return a;
}
