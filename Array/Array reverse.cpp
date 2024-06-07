#include<iostream>
#include<algorithm>
using namespace std;
int main (){
int arr[]={12,3,245,35,64,35,768,57,86,58,76,756,45,46,80,60};

int size=sizeof(arr)/sizeof(arr[0]);

reverse(arr, arr + size);
cout<<"reversed Array : [ ";
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";

}
  cout<<"]";

return 0;

}
