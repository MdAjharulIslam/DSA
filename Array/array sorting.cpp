#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int array[]={50,40,45,70,76,98,32,43,78,99};

int size=sizeof(array)/sizeof(array[0]);

sort(array , array+size);

for(int i=0;i<size;i++){
cout<<array[i]<<" ";

if(i<size-1){

    cout<<",";
}

}
cout<<endl;

return 0;

}
