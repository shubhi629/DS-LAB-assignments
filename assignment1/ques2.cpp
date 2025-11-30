#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"ENTER THE SIZE OF ARRAY : ";
    cin>>n;

    int arr[n];
cout<<"enter the values of array : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"ARRAY : "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]==arr[j]){
                arr[i]=-99;
            }
        }
    }
    cout<<"AFTWE DELETING DUPLICATES : "<<endl;
    for(int i =0;i<n;i++){
        if(arr[i]!=-99){
            cout<<arr[i]<<" ";
        }
    }
}