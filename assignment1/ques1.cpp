#include<iostream>
using namespace std;
void create(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
       for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}


void insert(){
       int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

       for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    int number;
    cout<<"enter the number u want to insert";
    cin>>number;
    
    int pos;
    cout<<"enter the pos: ";
    cin>>pos;

    for(int i =n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=number;
    n++;

    cout<<"after insertion : ";
    for(int i =0;i<n;i++){
        cout<<arr[i];
    }
}

void del(){
          int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

       for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    int number;
    cout<<"enter the number u want to delte";
    cin>>number;

    int pos=-1;

 for(int i =0;i<n;i++){
    if(arr[i]==number){
        pos=i;
        break;
    }
 }
 if(pos==-1){
    cout<<"number not found";
 }else{
    for(int i =pos;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"array after delteion : ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
 }
     
}
void search(){
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
cout<<"enter the number : ";
cin>>number;
    int found=0;
    int pos=0;
for(int i =0;i<n;i++){
    if(arr[i]==number){
    found =1;
    pos=i;
}
}
if(found==0){
    cout<<"number is not there";
}else{
    cout<<"number is present at "<<pos<<" index";
}
}

int main(){
int choice;
cout<<"Menu"<<endl;
cout<<" case 1 :create and display"<<endl;
cout<<"case 2 : insertion "<<endl;
cout<<"case 3 : deltion "<<endl;
cout<<"case 4 : linear search"<<endl;
cout<<"case 5 : exit the program "<<endl;
cout<<"chose the thing u want to do ";
cin>>choice;
switch(choice){
    case 1:create();break;
     case 2:insert();break;
      case 3:del();break;
      case 4: search();break;
      case 5 : cout<<"program ended"; break;
}
}