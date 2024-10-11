#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> neck;
        for(int i = 0; i < n; i++){
            int v;
            cin >> v;
            // cout << v << " ";
            neck.push_back(v);
            // cout << "vneck: " <<  neck[i] << "---";
        }

        auto first1 = neck.begin();
        auto last1 = neck.end();
        sort(first1, last1);

        vector<int> brace;
        for(int i = 0; i < n; i++){
            int v;
            cin >> v;
            // cout << v << " ";

            brace.push_back(v);
        }
        auto first2 = brace.begin();
        auto last2 = brace.end();
        sort(first2, last2);

        for(int i = 0; i < n; i++){
            cout << neck[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < n; i++){
            cout << brace[i] << " ";
        }
        cout << endl;
   }

}
