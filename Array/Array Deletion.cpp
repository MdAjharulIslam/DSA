#include<iostream>
using namespace std;

void display(int arr[],int size){
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}

   cout<<endl;
}

void deletion(int arr[],int size,int index){

for(int i=index;i<size;i++){

    arr[i]=arr[i+1];
    }

}
int main(){
 int arr[100]={1 , 2, 3, 4, 5};
 int size=5;
 int index=3;

 display(arr,size);
 deletion(arr,size,index);
 size-=1;
 display(arr,size);
 return 0;
}
