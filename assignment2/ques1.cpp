#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter n : ";
    cin>>n;

    int arr[n];

    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    int number;
    cout<<"enter number :  ";
    cin>>number;
int found =0;
    int low=0;
    int high =n-1;
    while(low<=high){
        int mid=(high+low)/2;

        if(arr[mid]==number){
            cout<<"number is found at index = "<<mid;
            found =1;
            break;
        }else if(arr[mid]<number){
            low=mid+1;
        }
        else {
            high = mid-1;
        }
    }
if(found==0){
    cout<<"number not found ";
}
}