/* 
 * File:   main.cpp
 * Author: Taylor Nesby
 *
 * Created on March 3, 2014, 1:10 PM
 */

#include <cstdlib>
#include<iostream>
#include<ctime>

using namespace std;

//function prototypes
int * fillArray(int);
void prntArray(int *, int, int);
void sort(int *, int*, int);
int maxFreq(int *, int);
int nuModes(int *, int, int);
void destroy(int*);


int main(int argc, char** argv) 
{
    //variables
    const int size=105;
    int brray[size];
    //fill array with 0-9
    int *array=fillArray(size);
    //print array
    prntArray(array, size,10);
    //copy and sort array
    sort(array, brray,size);\
    //display sorted array
    prntArray(brray, size,10);
    //what is max frequency?
    cout<<"Max frequency: "<<maxFreq(brray , size);
    
    destroy(array);
    
    return 0;
}
//repetitive count with 1 digit elements
int *fillArray(int n)
{
    //allocate memory
    int *a=new int [n];
    //fill array
    for(int i=0; i<n;i++)
        a[i]=i%10;
    
    return a;
}
void prntArray(int a[], int n, int perLine)
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<< a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void sort(int a[], int b[], int n)
{
    //copy
    for(int i=0; i<n;i++)
        b[i]=a[i];
    //sort
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(b[i]>b[j])
            {
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                
            }
                
    
}
//requires sorted array for an input
int maxFreq(int a[], int n)
{
    //declare counters
    int count=1, max=1;
    //loop and compare
    for(int i=1;i<n;i++){
       if(a[i-1]==a[i]){
                count++;
                if(count>max) max=count;
               }else{
           count=1;
       }
        
    }
        
    
    
    return max;
 }
void destroy(int*a)
{
    delete [] a;
}
