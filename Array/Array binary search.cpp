#include<iostream>
#include<stdio.h>
using namespace std;

int binarysearch(int arr[], int size,int element){
int low,mid,high;
low=0;
high=size-1;
while(low<=high){
mid=(low+high)/2;
if(arr[mid]==element) {
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

  int arr[]={1,3,4,5,6,7,8,12,34,56,78,90,100};
  int size=sizeof(arr)/sizeof(arr[0]);

  int element=100;
  int searchindex=binarysearch(arr,size,element);
  printf("the element %d was found at index %d",element,searchindex);

return 0;
}
