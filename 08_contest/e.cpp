#include <bits/stdc++.h>
#include <string>
using namespace std;


int eval(vector<string>& A)
//https://www.geeksforgeeks.org/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-java/
{
    stack<int> st;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "+" && A[i] != "-" && A[i] != "/"
            && A[i] != "*") {
            st.push(stoi(A[i]));
            continue;
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (A[i] == "+")
                st.push(a + b);
            else if (A[i] == "*")
                st.push(a * b);
            else
                st.push(a % b);
        }
    }
    return st.top();
}

vector<string>& lista;

void simple_tokenizer(string s)
// https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
{
    stringstream ss(s);
    string word;
    while (ss >> word) {
        lista.push_back(word);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    lista = new vector<string>&();
    string input;
    simple_tokenizer(input);

    stack<string> coisas;
    cout << eval(lista);

}
