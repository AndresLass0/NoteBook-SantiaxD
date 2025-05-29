// KMP - Búsqueda de patrones (pattern matching)
// Cuenta cuántas veces aparece el string p en s usando la Prefix Function
// Complejidad: O(|s| + |p|)

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pf[j - 1];
        if (s[i] == s[j])
            j++;
        pf[i] = j;
    }
    return pf;
}

// Cuenta las apariciones del patrón p en el texto s
int kmp(string &s, string &p) {
    int n = s.size(), m = p.size(), cnt = 0;
    vector<int> pf = prefix_function(p);
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pf[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == m) {
            cnt++;           // Match completo de p en s
            j = pf[j - 1];   // Continuar buscando sin retroceder
        }
    }
    return cnt;
}

/*
Ejemplo de uso:

string s = "ababcababcababc";
string p = "ababc";

int res = kmp(s, p); // res = 3

// "ababc" aparece en posiciones: 0, 5, 10
*/
