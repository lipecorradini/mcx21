#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
    unsigned n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b, c;
        int x, y, z;

        cin >> a >> b >> c;
        int resp_x = 500;
        int resp_y = 500;
        int resp_z = 500;
    
        for(x = -21; x <= 21; x++) if (x*x <= c){
            for(y = x+1; y <= 100; y++) if (x*x + y*y <= c){
                for(z = y+1; z <= 100; z++)
                    if(x + y + z == a && x * y * z == b && x*x + y*y + z*z == c){
                        if (x < resp_x){
                            resp_x = x;
                            resp_y = y;
                            resp_z = z;
                        }
                        else if(x == resp_x){
                            if (y < resp_y){
                                resp_x = x;
                                resp_y = y;
                                resp_z = z;
                            }
                        }
                    }
                }
            }
        if(resp_x == 500){
            cout << "No solution." << '\n';
        }
        
        else{
            cout << resp_x << " " << resp_y << " " << resp_z << '\n';
        }

    }

}
