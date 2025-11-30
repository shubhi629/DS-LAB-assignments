#include<iostream>
using namespace std;
int linearsearch(int arr[],int n){
    for(int i =0;i<n-1;i++){
        if(arr[i]!=i+1){
            return i+1;
        }
}
return n;
}

int binaryserach(int arr[],int n){
    int low=0;
    int high=n-2;
while(low<=high){
    int mid=(high+low)/2;

    if(arr[mid]==mid+1){
        low=mid+1;
    }else{
        high=mid-1;
    }
}
return low+1;
}
int main(){
    int n ;
    cout<<"enter the size of array : ";
    cin>>n;
int arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    for(int i =0;i<n-1;i++){
        cout<<arr[i]<<" ";
    }
cout<<"Number missing  by linear search : "<<linearsearch(arr, n)<<endl;
cout<<"NUMBER MISSING BY BINARY SERACH  : "<<binaryserach(arr,  n);
}