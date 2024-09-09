#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    while(cin >> n){

            if(n == 0) break; 

            vector<pair<int, int>> arr(2*n);

            for (int i = 0; i < 2 * n; i++)
            {
                int x, y;
                cin >> x >> y;
                arr[i].first = x;
                arr[i].second = y;
            }

            int tam = arr.size();

            bool isover = false;

            for (int a = -500; a < 501; a++)
            {
                for(int b = -500; b < 501; b++){
                
                    int cont = 0;
                    bool flag = true;
                    int sum;
                
                    for (int j = 0; j < tam; j++)
                    {
                        sum = arr[j].first * a + arr[j].second * b;
                        if (sum > 0){
                            cont++;
                        }
                        
                        if (sum == 0)
                        {
                            flag = false;
                            break;
                        }
                    }

                if (cont == n && flag)
                    {
                        cout << a << " " << b << '\n';
                        isover = true;
                        break;
                    }
            }
            if(isover){
                    break;
                }
            }
        }
    }
