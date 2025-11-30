// #include<iostream>
// using namespace std;
// int main (){

//     int sp1[4][3]={{3,3,3},{0,1,3},{2,1,6},{2,2,9}};
//     int sp2[4][3]={{3,3,3},{0,1,5},{0,2,8},{2,1,7}};                        ADDITION 
                                                                            
//     int sp3[30][3];
//     int i=1,j=1,k=1;

//     int l1=sp1[0][2];
//     int l2=sp2[0][2];

//     //first row dimension
//     sp3[0][0]=sp1[0][0];
//     sp3[0][1]=sp1[0][1];
//     while(i<=l1 && j<=l2){
//         if
//             ( sp1[i][0]<sp2[j][0] || (sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1]) ){
//                 sp3[k][0]=sp1[i][0];
//                 sp3[k][1]=sp1[i][1];
//                 sp3[k][2]=sp1[i][2];
//                 i++;k++;
//         }

//         else if   ( sp1[i][0]>sp2[j][0] || (sp1[i][0]==sp2[j][0] && sp1[i][1]>sp2[j][1]) ){
//                 sp3[k][0]=sp2[j][0];
//                 sp3[k][1]=sp2[j][1];
//                 sp3[k][2]=sp2[j][2];
//                 j++;k++;
//         }
//         else //same rows and columns value
//         {
//             sp3[k][0]=sp1[i][0];
//             sp3[k][1]=sp1[i][1];
//             sp3[k][2]=sp1[i][2]+sp2[j][2];
//                 j++;i++;k++;
//         }
//     }

//     //copy remaining elements
//     while(i<=l1){
//         sp3[k][0]=sp1[i][0];
//                 sp3[k][1]=sp1[i][1];
//                 sp3[k][2]=sp1[i][2];
//                 i++;k++;
//     }
//     while(j<=l2){
//         sp3[k][0]=sp2[j][0];
//                 sp3[k][1]=sp2[j][1];
//                 sp3[k][2]=sp2[j][2];
//                 j++;k++;
//     }

//     sp3[0][2]=k-1;

//     cout<<"addition of two sparse matrix:\n";
//     cout<<"rows\tcolumns\tvalues\n";
//     for(int x=0;x<=sp3[0][2];x++){
//         cout<<sp3[x][0]<<"\t"<<sp3[x][1]<<"\t"<<sp3[x][2]<<endl;
//     }
// }


#include<iostream>
using namespace std;

int main() {

    int m, n, num;
    cin >> m >> n >> num;     // rows, columns, non-zero count

    int a[100][3];

    for(int i = 0; i < num; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    // -------- TRANSPOSE --------
    cout << "Transpose:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < num; j++) {
            if(a[j][1] == i) {
                cout << a[j][1] << " "
                     << a[j][0] << " "
                     << a[j][2] << endl;
            }
        }
    }

    // -------- SECOND MATRIX INPUT --------
    int m2, n2, num2;
    cin >> m2 >> n2 >> num2;

    int b[100][3];

    for(int i = 0; i < num2; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    // -------- MULTIPLICATION --------
    cout << "Multiplication:\n";

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n2; j++) {

            int sum = 0;

            for(int x = 0; x < num; x++) {
                if(a[x][0] == i) {
                    for(int y = 0; y < num2; y++) {
                        if(b[y][0] == a[x][1] && b[y][1] == j) {
                            sum += a[x][2] * b[y][2];
                        }
                    }
                }
            }

            if(sum != 0) {
                cout << i << " " << j << " " << sum << endl;
            }
        }
    }

    return 0;
}
