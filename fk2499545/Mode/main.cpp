/* 
 * File:   main.cpp
 * Author: Fuaad Khan
 * Created on March 3, 2014, 1:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void filAry(int[], int);
void prntAry(int[], int, int);
void sort(int[], int [], int);
int maxFrq(int [], int);
int nuModes(int [], int, int);
//Execution begins here!
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int array[SIZE], brray[SIZE];
    //Fill array with 0-9
    filAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    cout<<endl;
    //Sort copied array
    sort(array,brray,SIZE);
    //Print copy
    prntAry(brray,SIZE,10);
    //what is the max frequency
    cout<<"The max frequency in the array = "<<maxFrq(brray,SIZE)<<endl;

    return 0;
}

int nuModes(int a[], int n, int){
    
}
//Requires sorted array
int maxFrq(int a[], int n){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}

void sort(int a[], int b[], int n){
    for(int i=0;i<n;i++){
    b[i]=a[i];
    }  
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

void prntAry(int a[], int n, int perLine){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Repetitive count with 1 digit elements
void filAry(int a[], int n){
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
}