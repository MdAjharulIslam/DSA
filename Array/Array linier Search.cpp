#include<iostream>
using namespace std;
int main(){

int arr[]={10,20,30,40,50,60,70,80,90};
int found=0;
int number;
cout<<"Enter a number: ";
cin>>number;

int sizearr=sizeof(arr)/sizeof(arr[0]);

for(int i=0;i<sizearr;i++){
if(arr[i]==number){
        found=1;
        cout << "number = "  <<number <<" found  at index "<< i <<endl;
        break;
}
}
if(!found){
    cout<<number<<" not found this number"<<endl;
}


}
