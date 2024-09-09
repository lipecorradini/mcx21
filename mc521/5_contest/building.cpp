#include <bits/stdc++.h>

using namespace std;

int find_total_per_height(int height, vector<int> corals, int n){
    
    int sum_h = 0;
    for(int i = 0; i < n; i++){
        if(corals[i] < height){
            sum_h += height - corals[i];
        }
    }

    return sum_h;
}

int find_amount(int min, int max, vector<int> corals, int n, int x){
    
    int tot1 = find_total_per_height(min, corals, n);
    int tot2 = find_total_per_height(max, corals, n);

    int valor = tot1 - tot2;
    if (fabs(valor) <= 1)
        return (min + max) / 2;
    else if (valor > x)
        return find_amount(min, (min + max) / 2, corals, n, x);
    return find_amount((min + max) / 2, max, corals, n, x);
}

void solve(int n, int x){

    vector<int> corals(n);

    for(int i = 0; i < n; i++){
        cin >> corals[i];
    }
    cout << "aq" << '\n';

    int min = 0;
    int max = *max_element(corals.begin(), corals.end());

    cout << find_amount(min, max, corals, n, x);

}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

    unsigned v;

    cin >> v;

    int n, x;

    cout <<"cheg\n";
    for(int i = 0; i < v; i++){
        cin >> n >> x;
        solve(n, x);    
    }


}
