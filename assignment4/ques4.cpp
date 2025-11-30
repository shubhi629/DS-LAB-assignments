#include<iostream>
#include<queue>
using namespace std;

int main() {
    char s[100];
    cin >> s;

    queue<char> q;
    int freq[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        q.push(c);
        freq[c]++;

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
    return 0;
}