#include<iostream>
using namespace std;
int main(){
    int row;
    int col;
    cout<<"enter the no of rows : ";
    cin>>row;

    cout<<"enter the no of cols : ";
    cin>>col;
int arr[row][col];
    for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            cin>>arr[i][j];
        }
    }

        for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i =0;i<row;i++){
        int rowsum=0;
        for(int j =0;j<col;j++){
            rowsum+=arr[i][j];
        }
        cout<<"sum of " <<i+1<<"  row  " <<rowsum<<endl;
    }

    for(int j =0;j<col;j++){
        int colsum=0;
        for(int i=0;i<row;i++){
            colsum+=arr[i][j];
        }
        cout<<"sum of "<<j+1 <<  " colunm   " << colsum<<endl;
    }
}