#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t, buff;
    cin >> s;
    cin >> t;
    stack<int> pilha;

    int cont = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) cont ++;
    }

    cout << cont << endl;

    buff = s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            if(s[i] < t[i]) pilha.push(i);
            else{
                buff[i] = t[i];
                cout << buff << '\n';
            }
        }
    }

    while(!pilha.empty()){
        int value = pilha.top();
        pilha.pop();
        buff[value] = t[value];
        cout << buff << endl;
    }


}
