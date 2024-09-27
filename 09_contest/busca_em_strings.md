Busca em strings: encontrar os índices iniciais de uma substring em uma string maior


```cpp

#include <iostream>
#include <cstring>
using namespace std;

// Prints occurrences of pattern P in text T
void KMPSearch(char* P, char* T) {
    int M = strlen(P);
    int N = strlen(T);
    
    // Create lps[] that will hold the longest prefix suffix values for pattern
    int lps[M];
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(P, M, lps);
    
    int i = 0; // index for T
    int j = 0; // index for P

    while (i < N) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not match lps[0..lps[j-1]] characters
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Function to compute the LPS array
void computeLPSArray(char* P, int M, int* lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // Calculate lps[i] for i = 1 to M-1
    while (i < M) {
        if (P[i] == P[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


```