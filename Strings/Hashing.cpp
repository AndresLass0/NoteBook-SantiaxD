// ICPC Notebook - Polynomial Hashing
// Usar para comparar substrings en O(1), contar substrings distintos, detectar palíndromos, etc.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int add(int a, int b, const int &mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sbt(int a, int b, const int &mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

const int X[] = {257, 359};              
const int MOD[] = {1000000007, 1000000009}; 
vector<int> xpow[2];                   

void calc_xpow(int mxlen) {
    for (int j = 0; j < 2; ++j) {
        xpow[j].resize(mxlen + 1, 1);
        for (int i = 1; i <= mxlen; ++i)
            xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
}


struct hashing {
    vector<int> h[2];

    hashing(string &s) {
        int n = s.size();
        for (int j = 0; j < 2; ++j) {
            h[j].resize(n + 1);
            for (int i = 1; i <= n; ++i)
                h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
        }
    }

    // Hash del substring s[l..r-1] en O(1)
    ll value(int l, int r) {
        int a = sbt(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
        int b = sbt(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
        return (ll(a) << 32) + b; // Combinar ambos hashes
    }
};

// Ejemplo de uso
// string s = "abacaba";
// calc_xpow(s.size());
// hashing h(s);
// cout << h.value(0, 3); // hash de "aba"
// cout << (h.value(0, 3) == h.value(4, 7)); // comparar "aba" == "aba"

// Para comparar dos substrings s[l1..r1) y s[l2..r2), comparar h.value(l1,r1) == h.value(l2,r2)
// Para contar substrings únicos: almacenar todos los h.value(i,j) en un set
// Para detectar palíndromos: comparar hashes de s[l..r] y reverse(s)[n-r..n-l]
