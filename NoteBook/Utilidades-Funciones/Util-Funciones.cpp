
/*Rotar una matriz 90 grados*/

int n;
vii rotar(vii &a) {
  vii v(n, vi(n));
  forn(i,n) forn(j, n)
    v[i][j] = a[n - 1 - j][i];
  return v;
}

bool encendido(int mask, int i) return (mask & (1 << i));
int apagar_bit(int mask, int i) return (mask & ~(1 << i));
int encender_bit(int mask, int i) return (mask | (1 << i));
int alternar_bit(int mask, int i) return (mask ^ (1 << i));
int contar_bits(int mascara) {
    return __builtin_popcount(mascara); // para int
    // return __builtin_popcountll(mascara); // para long long
}