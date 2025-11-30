// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"enter the size of array : ";
//     cin>>n;
// int arr[n];
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }

//     int start=0;
//     int end=n-1;
//     while(start<=end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }

//     for(int i =0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }


// #include<iostream>
// using namespace std;
// int main(){
//    int n;
//     cout<<"enter the size of array : ";
//     cin>>n;
// int arr[n];
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }

//     int m ;
//     cout<<"enter m : ";
//     cin>>m;
//     int brr[m];
//     for(int i =0;i<m;i++){
//         cin>>brr[i];
//     }
// if(n==m ){
//     cout<<"MUULTIPLICATION = ";
// }else{
//     cout<<"no multiplication ";
// }
//     int res[n];
//     for(int i =0;i<n;i++){
//         res[i]=arr[i]*brr[i];
//     }

//     for(int i =0;i<n;i++){
//         cout<<res[i]<<" ";
//     }
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int row;
//     cout<<"enter no of rows : ";
//     cin>>row;
//     int col;
//     cout<<"enter the no of columnes : ";
//     cin>>col;
// int arr[row][col];
//     for(int i =0;i<row;i++){
//         for(int j =0;j<col;j++){
//             cin>>arr[i][j];
//         }
//     }

//         for(int i =0;i<row;i++){
//         for(int j =0;j<col;j++){
//             cout<<arr[i][j];
//         }
//         cout<<endl;
//     }

//     cout<<"TRANSVERSE : "<<endl;

//         for(int i =0;i<col;i++){
//         for(int j =0;j<row;j++){
//             cout<<arr[j][i]<<" ";
//         }
//         cout<<endl;
//     }
// }