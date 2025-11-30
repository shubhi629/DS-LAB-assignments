// #include<iostream>
// using namespace std;
// int main(){
//     int n ;
//     cout<<"enter the value of n : ";
//     cin>>n;
//     int arr[n]={1,2,3};
//     int matrix[n][n];
//     for(int i =0;i<n;i++){
//         for( int j =0;j<n;j++){
// if(i==j){
//     matrix[i][j]=arr[i];
// }else{
//     matrix[i][j]=0;
// }
//         }
//     }

//     for(int i =0;i<n;i++){
//         for(int j =0;j<n;j++){
//           cout<<matrix[i][j];
//         }
//         cout<<endl;
//     }
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter size of tri-diagonal matrix (n x n): ";
//     cin >> n;

//     int size = 3*n - 2;   // only 3n-2 elements needed
//     int arr[size];        // 1D array to store elements

//     // initialize with 0
//     for(int i=0;i<size;i++) arr[i]=0;

//     cout << "Enter matrix elements row-wise:\n";
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             int x;
//             cin >> x;
//             if(i==j) {
//                 arr[i-1] = x;             // main diagonal
//             } else if(i==j+1) {
//                 arr[n+i-2] = x;           // lower diagonal
//             } else if(i+1==j) {
//                 arr[2*n+i-2] = x;         // upper diagonal
//             }
//         }
//     }

//     // print matrix
//     cout << "\nTri-diagonal Matrix:\n";
//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             if(i==j) {
//                 cout << arr[i-1] << " ";
//             } else if(i==j+1) {
//                 cout << arr[n+i-2] << " ";
//             } else if(i+1==j) {
//                 cout << arr[2*n+i-2] << " ";
//             } else {
//                 cout << 0 << " ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter the size of array : ";
//     cin>>n;
// int matrix[n][n];
//     for(int i =0;i<n;i++){
// for(int j=0;j<n;j++){
//     if(i==j || i<j){
//         cin>>matrix[i][j];
//     }else{
//         matrix[i][j]=0;
//     }
// }
//     }

//     for(int i =0;i<n;i++){
//         for(int j =0;j<n;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter the size of array : ";
//     cin>>n;
// int matrix[n][n];
//     for(int i =0;i<n;i++){
// for(int j=0;j<n;j++){
//     if(i==j || i>j){
//         cin>>matrix[i][j];
//     }else{
//         matrix[i][j]=0;
//     }
// }
//     }

//     for(int i =0;i<n;i++){
//         for(int j =0;j<n;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of array : ";
    cin>>n;
int matrix[n][n];
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
        if(i>=j){
            cin>>matrix[i][j];
        }
    }
}
for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
        matrix[i][j]=matrix[j][i];
    }
}

for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}

}