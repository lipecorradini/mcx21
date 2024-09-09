#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;

   vector<int> seq(n);

   for(int i = 0; i < n; i++){
        cin >> seq[i];
   }

    int first = 0, last = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        if(last != 0 && seq[last - 1] > seq[last]){
            if(last - first > tot) tot = last - first;
            first = i;
            last = i + 1;     
        }

        else if(i == n - 1){
            if(last - first + 1 > tot) tot = last - first + 1;

        }

        else{
            last ++;
        }
    }

    cout << tot << '\n';

}
