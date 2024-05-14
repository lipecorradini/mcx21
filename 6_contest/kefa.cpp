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
        //  cout << "start : first -" << first << " last- " << last << " i = " << i << '\n';
        if(last != 0 && seq[last - 1] > seq[last]){
            if(last - first > tot) tot = last - first;
            first = i;
            last = i + 1;     
            // cout << " quebrou! com tot=" << tot << '\n';
        }

        else if(i == n - 1){
            if(last - first + 1 > tot) tot = last - first + 1;
            // cout << " cabou! com tot=" << tot << '\n';

        }

        else{
            // cout << " entrou!" << '\n';
            last ++;
        }
        // cout << "end: first- " << first << " last- " << last << " i = " << i << '\n';
    }

    cout << tot << '\n';

}
