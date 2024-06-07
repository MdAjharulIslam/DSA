#include<iostream>
#include<stdio.h>
using namespace std;

int binarysearch(int arr[], int size,int element){
int low,mid,high;
low=0;
high=size-1;
while(low<=high){
    mid=(low+high)/2;

    if(arr[mid]==element){
        return mid;
    }

    if(arr[mid]<element){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return -1;

}

int main(){

int arr[]={5,7,8,9,10,11,12,23,34,45,67,70,75,80,90};
int size=sizeof(arr)/sizeof(arr[0]);
int element=12;
int searches=binarysearch(arr,size,element);

cout<<"the element: "<<element<<" was found at index: "<<searches<<endl;
return 0;
}
