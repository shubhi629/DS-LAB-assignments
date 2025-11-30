#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number n : ";
    cin>>n;
int arr[n];
    for(int i =0;i<n;i++){
cin>>arr[i];
    }

    for(int j=0;j<n;j++){
        cout<<arr[j];
    }

int count =0;
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]>arr[j]){
count =count+1;
            }
        }
    }

    cout<<"The total number of inversion = "<<count;
}