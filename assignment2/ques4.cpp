// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s1, s2;                        Concatenate one string to another  
//     cout << "Enter first string: ";
//     cin >> s1;
//     cout << "Enter second string: ";
//     cin >> s2;

//     string result = s1 + s2;   // concatenation
//     cout << "Concatenated string: " << result << endl;
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str;
//     cout << "Enter a string: ";              reverse a string
//     cin >> str;

//     string rev = "";
//     for (int i = str.length() - 1; i >= 0; i--) {
//         rev += str[i];
//     }

//     cout << "Reversed string: " << rev << endl;
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string str;                                 delete all vowels
//     cout << "Enter a string: ";
//     cin >> str;

//     string result = "";
//     for (char c : str) {
//         if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
//               c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
//             result += c;
//         }
//     }

//     cout << "String without vowels: " << result << endl;
//     return 0;
// }



// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of strings: ";
//     cin >> n;

//     string arr[50];
//     cout << "Enter " << n << " strings:\n";
//     for (int i = 0; i < n; i++) cin >> arr[i];                        sorting

//     // simple bubble sort
//     for (int i = 0; i < n-1; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 string temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     cout << "Strings in alphabetical order:\n";
//     for (int i = 0; i < n; i++) cout << arr[i] << endl;
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string in UPPERCASE: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;   // convert to lowercase
        }
    }

    cout << "Lowercase string: " << str << endl;
    return 0;
}
