

//====================VECTOR=====================
/*Rotar una matriz 90 grados*/

int n;
vii rotar(vii &a) {
  vii v(n, vi(n));
  forn(i,n) forn(j, n)
    v[i][j] = a[n - 1 - j][i];
  return v;
}


//====================BITS=======================
bool encendido(int mask, int i) return (mask & (1 << i));
int apagar_bit(int mask, int i) return (mask & ~(1 << i));
int encender_bit(int mask, int i) return (mask | (1 << i));
int alternar_bit(int mask, int i) return (mask ^ (1 << i));
int contar_bits(int mascara) {
    return __builtin_popcount(mascara); // para int
    // return __builtin_popcountll(mascara); // para long long
}


//====================STRINGS=======================

//Divide el string s por cada espacio ' ' y devuelve un vector<> con los substrings resultantes.
//Para dividir el string por un caracter especifico, agregar el parametro c y cambiar el while.

vector<string> split(const string &s/*, char c*/) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    // while (getline(ss, sub, c)) v.pb(sub);
    return v;
}