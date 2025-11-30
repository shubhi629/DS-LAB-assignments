#include<iostream>
using namespace std;
int main(){
int n;
    cout<<"enter the number n ";
    cin>>n;

    int arr[n];
   for(int i =0;i<n;i++){
        cin>>arr[i];
    }
for(int i =0;i<n;i++){
    for(int j =i+1;j<n;j++){
        if(arr[j]==arr[i]){
            arr[i]=-9989;
        }
    }
}
int count=0;
for(int i =0;i<n;i++){
    if(arr[i]!=-9989){
        cout<<arr[i]<<" ";
        count+=1;
    }
}

cout<<"total distinct number now = "<<count;
}