
#include<bits/stdc++.h>
using namespace std;

vector<long long> ans;
// https://www.geeksforgeeks.org/trial-division-algorithm-for-prime-factorization/?ref=oin_asr1
int TrialDivision(long long N){

    int i = 2;
 
    // Computing the square root of
    // the number N
    int k = ceil(sqrt(N));
 
    // While loop till the
    // square root of N
    while(i<= k){
 
        // If any of the numbers between
        // [2, sqrt(N)] is a factor of N
        // Then the number is composite
        if(N % i == 0)
            return 0;
        i += 1;
    }

    return 1;
}
/* driver function */
int main()
{
    long long n; cin >> n;
    while(n){

    }
}