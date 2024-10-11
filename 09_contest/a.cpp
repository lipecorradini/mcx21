#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// the code below was extracted from https://cp-algorithms.com/string/manacher.html

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    cout << t << endl;
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        
        string v;
        if(cin >> v){
           
            vector<int> ans;
            ans = manacher(v);
            int max = 0;
            int imax = 0;
            for(int i = 0; i < ans.size(); i++){
                if(ans[i] >= max){
                    max = ans[i];
                    imax = i;
                }
            }

            cout << "imax is: " << imax << endl;
            // cout << "imax: " << imax << endl;

            if(imax == ans.size()/2 && max == ans.size() - 2){ // falta adicionar condicao do max
                cout << v; // maior palíndromo está na metade, já é um palíndromo
            }


            else{
                int index = ans.size() - imax + 1; // indice que começa a repetir
                // cout << "index: " << index << endl;
                // cout << "tamanho: " << ans.size() << endl;

                cout << v;
                for (int i = index - 1; i >= 0; i--){
                    cout << v[i];
                }
                cout << endl << "string until the imax: " << endl;
                for(int i = 0; i < imax; i++){
                    cout << v[i] << "(" << ans[i] << ")\n";
                }
            }
            cout << endl;
            for(auto x: ans){
                cout << x << " ";
            }
            cout << endl;
    
        }else{
            break;
        }
    }

}
