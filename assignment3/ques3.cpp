// #include<iostream>
 #include<string>
 #include <stack>
 using namespace std;

// bool areparanthesisbalanced( const string &expr){
//     stack<char> s;
//     for(char c : expr){
//         if(c=='('||c=='['||c=='{' ){
//             s.push(c);
//         }else if(c==')'||c=='}'||c==']'){
//             if(s.empty()){
//                 return false;
//             }
//             char top = s.top();
//             s.pop();

//             if((c=='(' || c !=')')||(c=='{' || c !='}')||(c=='[' || c !=']')){
//                 return false;
//             }
//         }
//     }
//     return s.empty();
// }
// int main(){
//  string expression;
//  cout<<"enter the string : ";
//  cin>>expression;
 
//  if(areparanthesisbalanced(expression)){
//     cout<<"yes the paranthsis are balanced";
//  }else{
//     cout<<"paranthesis is not balanced ";
//  }
// }


#include<iostream>
#include<string>
#include<stack>

bool bracket(const string &expr){
    stack<char> s;

    for(char c : expr){
        if(c=='('||c=='{'||c=='['){
            s.push(c);
        }else if(c==')' || c=='}' || c==']'){
            if(s.empty()){
                return false;
            }
            char top = s.top();
            s.pop();

            if((c=='(' && c!=')' ||
            c=='{' && c!='}'||
        c=='[' && c!=']')){
            return false;
        }
        }
    }
    return s.empty();
}

int main(){
    string e;
    cout<<"enter the string ";
    cin>>e;

    if(bracket(e)){
        cout<<"it is okay !!";
    }else{
        cout<<"cant be okay ";
    }
}