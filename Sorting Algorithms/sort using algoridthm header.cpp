#include<iostream>
#include<algorithm>
using namespace std;
int main(){

int arr[]={90,34,65,12,567,43,23,76,67,132,76,9};
int n=sizeof(arr)/sizeof(arr[0]);
sort(arr,arr+n);

cout<<"sorted array is :";

for(int i=0;i<n;i++){

cout<<arr[i]<<" ";
}

    return 0;
}